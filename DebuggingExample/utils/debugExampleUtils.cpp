#include "debugExampleUtils.h"

DebugExampleUtils::DebugExampleUtils() {
}

DebugExampleUtils::~DebugExampleUtils() {
}

void DebugExampleUtils::delay(int time) {
    sleep(time);
    printf("Sleep finished");
}
