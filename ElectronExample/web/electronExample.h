#ifndef ELECTRONEXAMPLE_WEB_ELECTRONEXAMPLE_H_
#define ELECTRONEXAMPLE_WEB_ELECTRONEXAMPLE_H_
#include <iostream>

class Calculator {
 public:
  Calculator();
  ~Calculator();
  double addNumbers(float a, float b);
  double substractNumbers(float a, float b);
  double multiplyNumbers(float a, float b);
  double divideNumbers(float a, float b);
};
#endif  // ELECTRONEXAMPLE_WEB_ELECTRONEXAMPLE_H_
