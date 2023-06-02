include ../Makefile.Boost

EMSCRIPTEN_IMAGE = emscripten/emsdk:3.1.28
DEBUG += -g -fdebug-compilation-dir='.'
EMCC_FLAGS += -fwasm-exceptions $(SOCKET_FLAGS)
SOCKET_FLAGS += -s WEBSOCKET_URL="$(WEBSOCKET_URL)" -s WEBSOCKET_SUBPROTOCOL="binary" -s SOCKET_DEBUG=1
WEBSOCKET_HOST = 127.0.0.1
WEBSOCKET_PORT = 3333
WEBSOCKET_URL = ws://$(WEBSOCKET_HOST):$(WEBSOCKET_PORT)/

compileCppBoostExample: createBuildDir getBoostLibrary
	g++ $(INCLUDE_LIBRARIES) $(SRCS) -o $(BUILD_DIR)/$(SRCS:.cpp=)

runCpp:
	@./$(BUILD_DIR)/$(SRCS:.cpp=)

runWebsocat:
	@docker run --rm -it --network host solsson/websocat -v -s $(WEBSOCKET_PORT)