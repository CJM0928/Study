#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int start_num, int end_num) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int l = start_num - end_num;
    int* answer = (int*)malloc(( l + 2 ) * sizeof(int));
    for(int i = 0; i <= l; i++){
        answer[i] = start_num - i;
    }
    return answer;
}