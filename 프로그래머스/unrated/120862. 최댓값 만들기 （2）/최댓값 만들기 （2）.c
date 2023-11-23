#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    int l =numbers_len;
    int max = 0;
    int idx = 0;
    for(int i = 0; i < l; i++){
        idx = 0;
        for(int j = 0; j < l; j++){
            if(i != idx){
            int n = numbers[i] * numbers[idx++];
                if(n > max){
                    max = n;
                }
            }
        }
    }
    answer = max;
    // numbers의 원소들을 곱해서 비교해야하는데 두개밖에없으면 비교할 값이 없으니
    // 두개 원소를 곱해서 나온값을 출력하면된다.
    if(l == 2){
        answer = numbers[0] * numbers[1];
    }
    return answer;
}