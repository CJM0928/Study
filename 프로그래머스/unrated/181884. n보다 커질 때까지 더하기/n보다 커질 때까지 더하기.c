#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len, int n) {
    int l = numbers_len;
    int answer = 0;
    for(int i = 0; i<l; i++){
        answer += numbers[i];
        if(answer > n){
            break;
        }
    }
    return answer;
}