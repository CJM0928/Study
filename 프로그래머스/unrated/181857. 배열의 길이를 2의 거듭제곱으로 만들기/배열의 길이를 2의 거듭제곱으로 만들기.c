#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// arr_len은 배열 arr의 길이입니다.
// 2의 거듭제곱은 2^1 2^2 2^3 과같은 의미
// 이 문제는 arr의 길이가 6이라면 2의 제곱이 되기위해서 2개의 배열을 추가해 길이8을 만들어야함.
// length를 2를주고 arr의 길이랑 비교해서 작으면 계속 2를 곱해주는 방법을 사용
int* solution(int arr[], size_t arr_len) {
    int l = arr_len;
    int length = 2;
    int idx = 0;
    while(length < l){
        length = length * 2;
    }
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((length+1)*sizeof(int));
    for(int i = 0; i < length; i++){
        if(i >= l){
            answer[idx++] = 0; 
        }else{
            answer[idx++] = arr[i];
        }
    }
    return answer;
}