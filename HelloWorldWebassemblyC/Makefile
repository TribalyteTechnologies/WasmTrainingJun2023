include ../Makefile

EMCC_FLAGS += -s EXPORTED_RUNTIME_METHODS=[stringToUTF8] -s EXIT_RUNTIME=1
FILE = ExampleFile.txt
FILE_PRELOAD = --preload-file $(FILE)
SRCS = $(wildcard *.c)
SRCS_JS = $(notdir $(patsubst %.c, %.js, $(SRCS)))
SRCS_WASM = $(notdir $(patsubst %.c, %.wasm, $(SRCS)))