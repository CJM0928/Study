#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len, int n) {
    int answer = 0;
    int l = array_len;
    for(int i = 0; i < l; i++){
        if(array[i] == n){
            answer++;
        }
    }
    return answer;
}