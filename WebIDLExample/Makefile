include ../Makefile

PYTHON = python3
WEBIDL_BINDER_SRCS = /emsdk/upstream/emscripten/tools/webidl_binder.py
IDL_FILE = webIDL.idl
JS_GLUE = glue.js
CPP_GLUE = glue.cpp
BUILD_OUTPUT = webIDL.js
SRCS = webIDL.cpp
SRCS_DEPENDENCIES = glueWrapper.cpp

compileExampleIdl: createBuildDir
	$(PYTHON) $(WEBIDL_BINDER_SRCS) $(IDL_FILE) glue
	$(EMCC) $(SRCS) $(SRCS_DEPENDENCIES) --post-js $(JS_GLUE) -v -o $(BUILD_DIR)/$(BUILD_OUTPUT)
	@echo "Compilation done"

dockerCompileExampleIdl: createBuildDir
	@docker run --rm -v $(CURRENT_DIR)/../Makefile:/Makefile -v $(CURRENT_DIR):/src -u $(USER_ID):$(GROUP_ID) $(EMSCRIPTEN_IMAGE) make compileExampleIdl;

cleanExample::
	$(RM) $(JS_GLUE)
	$(RM) $(CPP_GLUE)