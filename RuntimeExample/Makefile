include ../Makefile

SRCS_RUN_WASM = $(wildcard */*.wasm)
BUILD_OUTPUT = $(SRCS_WASM)

run:
	@if [ ! -d $(BUILD_DIR) ]; then $(MKDIR) -p $(BUILD_DIR); fi
	docker run \
	-it \
	--rm \
	-v $(CURRENT_DIR):/app \
	-v $(CURRENT_DIR)/$(BUILD_DIR):/app/$(BUILD_DIR) \
	wasmedge/slim:0.12.0 \
	wasmedge $(SRCS_RUN_WASM)