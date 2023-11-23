#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    int l = numbers_len;
    for(int i = 0; i < l-1; i++){
        for(int j = i+1; j < l; j++){
            if(numbers[i] > numbers[j]){
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    answer = numbers[l - 1] * numbers[l - 2];
    return answer;
}