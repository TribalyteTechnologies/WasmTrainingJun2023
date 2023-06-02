include ../Makefile

DEBUG += -g -fdebug-compilation-dir='..'
EMCC_FLAGS += --bind
SRCS = $(wildcard */*.cpp)
ELECTRON_SRCS = ./node_modules
WEB_SRCS = ./web

compileExample::
	@$(CP) $(BUILD_DIR)/$(SRCS_JS) $(WEB_SRCS)/$(SRCS_JS)
	@$(CP) $(BUILD_DIR)/$(SRCS_WASM) $(WEB_SRCS)/$(SRCS_WASM)

cleanExample::
	@$(RM) $(ELECTRON_SRCS)
	@$(RM) $(WEB_SRCS)/$(SRCS_JS)
	@$(RM) $(WEB_SRCS)/$(SRCS_WASM)