EMCC = emcc
EMSCRIPTEN_IMAGE = emscripten/emsdk:3.1.36
APACHE_IMAGE = httpd:2.4
DEBUG =
OPTIMIZATION =
EMCC_FLAGS =
SRCS = $(wildcard *.cpp)
SRCS_JS = $(notdir $(patsubst %.cpp, %.js, $(SRCS)))
SRCS_WASM = $(notdir $(patsubst %.cpp, %.wasm, $(SRCS)))
SRCS_DEPENDENCIES =
INCLUDE_LIBRARIES =
BUILD_OUTPUT = $(SRCS_JS)
CD = cd
RM = rm -rf
CP = cp
MKDIR = mkdir
MV = mv
TAR = tar
WGET = wget
BUILD_DIR = build
CURRENT_DIR = $(shell pwd)
USER_ID = $(shell id -u)
GROUP_ID = $(shell id -g)
DIRECTORIES = $(wildcard */)
ALL_MAKEFILE_DIRS = $(foreach dir,$(DIRECTORIES),$(if $(wildcard $(dir)Makefile),$(dir)))
EXCLUDE_EXAMPLES_DIRS = $(filter Boost% WASI% WebIDL% WasmPacman% WasmAsteroids%, $(ALL_MAKEFILE_DIRS))
MAKEFILE_DIRS = $(filter-out $(EXCLUDE_EXAMPLES_DIRS), $(ALL_MAKEFILE_DIRS))
APACHE_IMAGE_NAME = apacheWebAssembly
HTDOCS_DIR = /usr/local/apache2/htdocs

all: init clean compile

init:
    ifneq ($(wildcard ./.git/*),)
	    @git config core.hooksPath .githooks
	    @echo "Git hooks set"
    endif

lint: init
	docker run  --rm  -v $(CURRENT_DIR):/e2e/ -w /e2e/  sharaku/cpplint cpplint $(shell find ./ -name *.hpp -or -name *.cpp -or -name *.h -or -name *.c);
	docker run  --rm  -v $(CURRENT_DIR):/usr/src/app -w /usr/src/app node:current-alpine3.16  sh -c "npm install eslint@8.40.0;  npx eslint ."

compile: init
	@docker run --rm -v $(PWD):/src -u $(USER_ID):$(GROUP_ID) $(EMSCRIPTEN_IMAGE) make emscriptenCompile
	@docker run --rm -v $(PWD):/src -u $(USER_ID):$(GROUP_ID) $(EMSCRIPTEN_IMAGE) make compileExampleIdl -C WebIDLExample/
	$(MAKE) -f Makefile.Boost compileBoost

emscriptenCompile:
	@$(foreach dir,$(MAKEFILE_DIRS), ($(MAKE) compileExample -C $(dir)) &&) :
	
clean:
	@$(foreach dir,$(MAKEFILE_DIRS),($(MAKE) cleanExample -C $(dir)) &&) :
	$(MAKE) -f Makefile.Boost cleanBoost
	$(MAKE) cleanExample -C WebIDLExample/

allExample: cleanExample compileExample

compileExample:: createBuildDir
	$(EMCC) $(DEBUG) $(OPTIMIZATION) $(EMCC_FLAGS) $(INCLUDE_LIBRARIES) $(SRCS) $(SRCS_DEPENDENCIES) -o $(BUILD_DIR)/$(BUILD_OUTPUT) $(FILE_PRELOAD)
	@echo "Compilation done"

dockerAllExample: cleanExample dockerCompileExample
	
dockerCompileExample: createBuildDir
	@docker run --rm -v $(CURRENT_DIR)/../Makefile:/Makefile -v $(CURRENT_DIR):/src -u $(USER_ID):$(GROUP_ID) $(EMSCRIPTEN_IMAGE) make allExample;

run:
	docker run -d --name $(APACHE_IMAGE_NAME) -v $(CURRENT_DIR):$(HTDOCS_DIR) -p 2345:80 $(APACHE_IMAGE)

stop:
	@docker stop $(APACHE_IMAGE_NAME)
	@docker rm $(APACHE_IMAGE_NAME)

cleanExample::
	@echo "Cleaning Objects"
	@$(RM) -rf $(BUILD_DIR)

test:
	docker run  --rm  -v $(CURRENT_DIR)/UnitTestExample:/usr/src/app -w /usr/src/app node:current-alpine3.16  sh -c "npm install jest;  npm test"	

createBuildDir:
	@if [ ! -d $(BUILD_DIR) ]; then $(MKDIR) -p $(BUILD_DIR); fi