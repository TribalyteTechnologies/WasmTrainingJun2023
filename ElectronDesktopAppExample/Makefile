include ../Makefile

DEBUG += -g -fdebug-compilation-dir='..'
EMCC_FLAGS += --bind
SRCS = $(wildcard */*.cpp)
ELECTRON_SRCS = ./node_modules
WEB_SRCS = ./web
ELECTRON_FORGE_FILE = forge.config.js

compileExample::
	@$(CP) $(BUILD_DIR)/$(SRCS_JS) $(WEB_SRCS)/$(SRCS_JS)
	@$(CP) $(BUILD_DIR)/$(SRCS_WASM) $(WEB_SRCS)/$(SRCS_WASM)

exportApp:
	npm i
	npm run exportApp

cleanExample::
	@$(RM) $(ELECTRON_SRCS)
	@$(RM) $(ELECTRON_FORGE_FILE)
	@$(RM) $(WEB_SRCS)/$(SRCS_JS)
	@$(RM) $(WEB_SRCS)/$(SRCS_WASM)