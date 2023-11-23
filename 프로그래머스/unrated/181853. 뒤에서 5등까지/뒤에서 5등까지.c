#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    int l = num_list_len;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((l+1)*sizeof(int));
    for(int i = 0; i < l; i++){
        for(int j = i+1; j < l; j++){
            if(num_list[i] > num_list[j]){
                int temp = num_list[i];
                num_list[i] = num_list[j];
                num_list[j] = temp;
            }
        }
    }
    for(int i=0; i < 5; i++){
        answer[i] = num_list[i];
    }
    return answer;
}