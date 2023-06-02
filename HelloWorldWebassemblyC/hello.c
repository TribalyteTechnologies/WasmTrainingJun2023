#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten/emscripten.h>


int javaScriptFunction(int a, int b);




int  EMSCRIPTEN_KEEPALIVE  subtract(int a, int b) {
  return a-b;
}

int  EMSCRIPTEN_KEEPALIVE  add(int a, int b) {
  return a+b;
}


int  EMSCRIPTEN_KEEPALIVE javaScriptFunction(int number1, int number2) {
int x = EM_ASM_INT({
      alert('press ok to get the result');
      return $0 + $1;
}, number1, number2);
return x;
}


EMSCRIPTEN_KEEPALIVE
extern void getString(char* str, char* buffer, int bufferLength) {
    printf("%s\n", str);
    strncpy(buffer, "string from C to Javascript ",  29);
    strcat(buffer, str);
}

int  EMSCRIPTEN_KEEPALIVE  *wasMalloc(size_t n) {
return malloc(n);
}


int EMSCRIPTEN_KEEPALIVE  *wasFree(void *ptr) {
free(ptr);
return 0;
}

int EMSCRIPTEN_KEEPALIVE  fileread(void *ptr) {
  FILE *file = fopen("ExampleFile.txt", "rb");
  if (!file) {
    printf("cannot open file\n");
    return 1;
  }
  while (!feof(file)) {
    char c = fgetc(file);
    if (c != EOF) {
      putchar(c);
    }
  }
  fclose(file);
  return 0;
}
