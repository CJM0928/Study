#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int l = num_list_len;
    int idx = 0;
    int a = 0;
    int b = 0;
    int answer = 0;
    for(int i = 0; i < l; i++){
        if(i % 2 == 0){
            a += num_list[i];
        }else if(i % 2 ==1){
            b += num_list[i];
        }
    }
    if(a >= b){
        answer = a;
    }else if(a < b){
        answer = b;
    }
    return answer;
}