#include "ionicReactExample.h"
#include <emscripten/bind.h>
#include <emscripten.h>

using namespace emscripten;

IonicReactExample::IonicReactExample() {
}

IonicReactExample::~IonicReactExample() {
}

std::string IonicReactExample::setPersonalData(const std::string& name, const std::string& email, const std::string& message) {
    return "The message from: " + name + " with email: " + email + " has been sent";
}

float IonicReactExample::additionOfNumbers(float n1, float n2) {
  return n1 + n2;
}

EMSCRIPTEN_BINDINGS(IonicReactExample) {
  class_<IonicReactExample>("IonicReactExample")
    .constructor<>()
    .function("setPersonalData", &IonicReactExample::setPersonalData)
    .function("additionOfNumbers", &IonicReactExample::additionOfNumbers);
}
