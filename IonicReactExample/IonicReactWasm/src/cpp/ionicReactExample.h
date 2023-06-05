#ifndef IONICREACTEXAMPLE_IONICREACTWASM_SRC_CPP_IONICREACTEXAMPLE_H_
#define IONICREACTEXAMPLE_IONICREACTWASM_SRC_CPP_IONICREACTEXAMPLE_H_
#include <iostream>

class IonicReactExample {
 public:
  IonicReactExample();
  ~IonicReactExample();
  std::string setPersonalData(const std::string& name, const std::string& email, const std::string& message);
  float additionOfNumbers(float n1, float n2);
};

#endif  // IONICREACTEXAMPLE_IONICREACTWASM_SRC_CPP_IONICREACTEXAMPLE_H_
