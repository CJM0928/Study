#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int k) {
    int l = arr_len;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((l+1)*sizeof(int));
    for(int i = 0; i < l; i++){
        if(k % 2 == 0){
            answer[idx++] = arr[i] + k;
        }else if(k % 2 != 0){
            answer[idx++] = arr[i] * k;
        }
    }
    return answer;
}