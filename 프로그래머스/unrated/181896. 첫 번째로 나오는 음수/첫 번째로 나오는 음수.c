#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int l = num_list_len;
    int answer = 0;
    int temp = -1;
    for(int i = 0 ; i < l; i++){
        if(num_list[i] < 0){
            temp = i;
            break;
        }
    }
    if(temp == -1){
        answer = -1;
    }
    answer = temp;
    return answer;
}