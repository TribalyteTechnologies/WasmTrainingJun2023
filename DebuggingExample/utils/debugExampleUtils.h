#ifndef DEBUGGINGEXAMPLE_UTILS_DEBUGEXAMPLEUTILS_H_
#define DEBUGGINGEXAMPLE_UTILS_DEBUGEXAMPLEUTILS_H_
#include <unistd.h>
#include <iostream>

class DebugExampleUtils {
 public:
    DebugExampleUtils();
    ~DebugExampleUtils();
    void delay(int time);
};

#endif  // DEBUGGINGEXAMPLE_UTILS_DEBUGEXAMPLEUTILS_H_
