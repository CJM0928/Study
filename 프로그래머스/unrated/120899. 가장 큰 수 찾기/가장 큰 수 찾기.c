#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int* solution(int array[], size_t array_len) {
    int l = array_len;
    int max = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2*sizeof(int));
    for(int i = 0; i < l; i++){
        if(array[i] >= max){
            max = array[i];
            answer[0] = array[i];
            answer[1] = i;
        }
    }
    return answer;
}