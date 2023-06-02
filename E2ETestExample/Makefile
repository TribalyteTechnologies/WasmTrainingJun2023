include ../Makefile

SRCS = $(wildcard */*.cpp)
DEBUG += -g -fdebug-compilation-dir='..'
EMCC_FLAGS += --bind -fwasm-exceptions
HTML_DIRECTORY = html/
CYPRESS_IMAGE_NAME = apacheWebAssembly

compileExample::
	@$(CP) $(BUILD_DIR)/$(SRCS_JS) $(HTML_DIRECTORY)
	@$(CP) $(BUILD_DIR)/$(SRCS_WASM) $(HTML_DIRECTORY)

cleanExample::
	@$(RM) $(HTML_DIRECTORY)$(SRCS_JS)
	@$(RM) $(HTML_DIRECTORY)$(SRCS_WASM)

run:
	@docker compose up --abort-on-container-exit