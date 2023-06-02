#include <iostream>
#include "utils/debugExampleUtils.h"

int main() {
    std::cout << "Hello world\n";

    DebugExampleUtils debugExampleUtils;

    for (int i = 0; i < 10; i++) {
        debugExampleUtils.delay(1);
        printf("Sleep %d\n", i);
    }

    return 0;
}
