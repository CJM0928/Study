#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    int l = arr_len;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((l + 1) * sizeof(int));
    for(int i = 0; i < l; i++){
        if(arr[i] >= 50 && arr[i] % 2 == 0){
            arr[i] = arr[i] / 2;
        }else if(arr[i] < 50 && arr[i] % 2 == 1){
            arr[i] = arr[i] * 2;
        }
    }
    for(int i = 0; i < l; i++){
        answer[idx++] = arr[i];
    }
    return answer;
}