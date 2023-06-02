include ../Makefile

WASMTIME_IMAGE = stevesanderson/wasmtime@sha256:f3c3dacd4999d26b14304f1ce74805ea278701c0c9b869f737f376946b9e8752
WASM_FILE = $(wildcard *.wasm)

run:
	docker run --rm --name wasmtimeRuntime -v .:/src -w /src $(WASMTIME_IMAGE) --dir=. $(WASM_FILE)

cleanExample:
	$(RM) $(WASM_FILE)