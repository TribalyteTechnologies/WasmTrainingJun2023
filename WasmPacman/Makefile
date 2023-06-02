include ../Makefile

EMSCRIPTEN_IMAGE = emscripten/emsdk:2.0.0

compilePacmanExample:
	$(MAKE) allw -C pacman

dockerCompilePacmanExample:
	@docker run --rm -v $(PWD):/src -v $(PWD)/../Makefile:/Makefile -u $(USER_ID):$(GROUP_ID) $(EMSCRIPTEN_IMAGE) make compilePacmanExample