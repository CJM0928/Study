#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int s = 0; // 연산횟수
    int l = num_list_len;
    for(int i = 0; i < l; i++){
        int n = num_list[i];
        if(n == 1){
            continue;
        }
        do{
            if(n % 2 == 0){
                n /= 2;
                s++;
            }else if(n % 2 != 0){
                n -= 1;
                n /= 2;
                s++;
            }
        }while(n > 1);
    }
    return s;
}