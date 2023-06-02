#ifndef WEBIDLEXAMPLE_WEBIDL_H_
#define WEBIDLEXAMPLE_WEBIDL_H_

#include <emscripten/bind.h>
#include <emscripten.h>
#include <string.h>
#include <iostream>

using namespace emscripten;

class Idlclass {
  public:
    int getVal();
    void setVal(int v);
  private:
    int val;
};

#endif  // WEBIDLEXAMPLE_WEBIDL_H_
