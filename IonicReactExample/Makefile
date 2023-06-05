include ../Makefile

EMCC_FLAGS += -lembind
DEBUG += -g -fdebug-compilation-dir='.'
APP_SRCS_DIR = IonicReactWasm/
SRCS_DIR = IonicReactWasm/src/cpp
SRCS = $(wildcard $(SRCS_DIR)/*.cpp)
NODE_MODULES_DIR = node_modules/

runAll: dockerCompileExample buildIonicApp runIonicApp

compileExample::
	@$(MV) $(BUILD_DIR) $(APP_SRCS_DIR)

cleanExample::
	@$(RM) $(APP_SRCS_DIR)$(BUILD_DIR)
	@$(RM) $(APP_SRCS_DIR)$(NODE_MODULES_DIR)

runIonicApp:
	@$(CD) $(APP_SRCS_DIR) && npm i && npm start

buildIonicApp:
	@$(CD) $(APP_SRCS_DIR) && npm i && npm run build