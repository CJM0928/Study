#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// V 는 || 얘기하는거같음
bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = (x1 || x2) && (x3 || x4);
    return answer;
}