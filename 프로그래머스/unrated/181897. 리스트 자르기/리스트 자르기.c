#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// slicer_len은 배열 slicer의 길이입니다.
// num_list_len은 배열 num_list의 길이입니다.
// 파이썬 기능을 c언어로 구현하기
int* solution(int n, int slicer[], size_t slicer_len, int num_list[], size_t num_list_len) {
    int l = num_list_len;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((l + 1)*sizeof(int));
    if(n == 1){
        for(int i = 0; i <= slicer[1]; i++){
            answer[idx++] = num_list[i];
        }
    }
    if(n == 2){
        for(int i = slicer[0]; i < l; i++){
            answer[idx++] = num_list[i];
        }
    }
    if(n == 3){
        for(int i = slicer[0]; i <= slicer[1]; i++){
            answer[idx++] = num_list[i];
        }
    }
    if(n == 4){
        for(int i = slicer[0]; i <= slicer[1]; i += slicer[2]){
            answer[idx++] = num_list[i];
        }
    }
    return answer;
}