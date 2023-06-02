#include "electronDesktopAppExample.h"
#include <emscripten/bind.h>
#include <emscripten.h>


using namespace emscripten;

Calculator::Calculator() {
}

Calculator::~Calculator() {
}

double Calculator::addNumbers(float a, float b) {
    return a + b;
}

double Calculator::substractNumbers(float a, float b) {
    return a - b;
}

double Calculator::multiplyNumbers(float a, float b) {
    return a * b;
}

double Calculator::divideNumbers(float a, float b) {
    return a / b;
}

EMSCRIPTEN_BINDINGS(calculator) {
  class_<Calculator>("Calculator")
    .constructor<>()
    .function("addNumbers", &Calculator::addNumbers)
    .function("substractNumbers", &Calculator::substractNumbers)
    .function("multiplyNumbers", &Calculator::multiplyNumbers)
    .function("divideNumbers", &Calculator::divideNumbers);
}
