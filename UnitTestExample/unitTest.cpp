#include <emscripten/bind.h>
#include <emscripten.h>
#include <string>
#include <iostream>

int EMSCRIPTEN_KEEPALIVE addInt(int a, int b) asm("addInt");
int addInt(int a, int b) {
  return a + b;
}

int EMSCRIPTEN_KEEPALIVE multInt(int a, int b) asm("multInt");
int multInt(int a, int b) {
  return a * b;
}

int  EMSCRIPTEN_KEEPALIVE square(int a) asm("square");
int  square(int a) {
  return a * a;
}
