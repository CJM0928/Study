#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer = 0;
    float num = num1;
    float num11 = num2;
    answer = num / num11 * 1000;
    return answer;
}