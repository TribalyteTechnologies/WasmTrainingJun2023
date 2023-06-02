#include "webIDL.h"

int Idlclass::getVal() {
    return Idlclass::val+1;
}

void Idlclass::setVal(int v) {
     Idlclass::val = v;
}
