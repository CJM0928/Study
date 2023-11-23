#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {     
    int n = 0;
    int m = 0;
    int sum = 0;
    for(int i = 0; i< num_list_len; i++){
        if(num_list[i] % 2 != 0){
            n = (n * 10) + num_list[i];
        }else if(num_list[i] % 2 == 0){
            m = (m * 10) + num_list[i];
        }
    }
    sum = n + m;
    return sum;
}