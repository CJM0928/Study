#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* stk = (int*)malloc(sizeof(int) * (arr_len+1));
    int i = 0;
    for(int index = 0; index <=arr_len; index++){
        if(i < arr_len && stk[0] == NULL){
            stk[index] = arr[i];
            i++;
        }else if(i < arr_len && stk[index-1] <arr[i]){
            stk[index] = arr[i];
            i++;
        }else if(i < arr_len && stk[index-1] >= arr[i]){
            stk[index - 1] = NULL;
            index -=2;
        }
    }
    return stk;
}