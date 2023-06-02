include ../Makefile

SRCS = $(wildcard */*.cpp)
SRCS_WORKER_JS = $(notdir $(patsubst %.cpp, %.worker.js, $(SRCS)))
DEBUG += -g -fdebug-compilation-dir='..'
EMCC_FLAGS += -std=c++11 -pthread -s PROXY_TO_PTHREAD
HTML_DIRECTORY = html/

compileExample::
	@$(CP) $(BUILD_DIR)/$(SRCS_JS) $(HTML_DIRECTORY)
	@$(CP) $(BUILD_DIR)/$(SRCS_WASM) $(HTML_DIRECTORY)
	@$(CP) $(BUILD_DIR)/$(SRCS_WORKER_JS) $(HTML_DIRECTORY)

cleanExample::
	@$(RM) $(HTML_DIRECTORY)$(SRCS_JS)
	@$(RM) $(HTML_DIRECTORY)$(SRCS_WASM)
	@$(RM) $(HTML_DIRECTORY)$(SRCS_WORKER_JS)

run:
	@docker compose up --abort-on-container-exit