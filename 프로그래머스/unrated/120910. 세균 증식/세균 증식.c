#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 반복문을 통해 2씩 곱하는 방법이 있다.

int solution(int n, int t) {
    int answer = n;
    for(int i = 0; i < t; i++){
        answer *= 2;
    }
    return answer;
}