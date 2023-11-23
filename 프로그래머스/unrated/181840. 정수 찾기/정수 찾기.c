#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len, int n) {
    int answer = 0;
    int l = num_list_len;
    for(int i = 0 ; i < l ;  i++){
        if(num_list[i] == n){
            return 1;
        }
    }
    return answer;
}