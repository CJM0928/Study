#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 나누기와 나머지랑 관련된 문제.
int solution(int n) {
    int answer = 0;
    int temp = 0;
    while(n > 0){
        temp = n % 10;
        n = n / 10;
        answer = answer + temp;
    }
    return answer;
}