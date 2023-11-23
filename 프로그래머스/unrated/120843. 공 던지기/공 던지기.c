#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
// numbers의 길이가 짝수일떄는
// 홀수인덱스가 계속 공을던지지만
// 길이가 홀수라면  홀수 -> 짝수 -> 홀수 -> 짝수 인덱스 순으로 돌아간다.
// 홀수에서 짝수할때는 홀수index - (index-1) 
// 짝수에서 홀수일때는 index = index - index 이런식으로
int solution(int numbers[], size_t numbers_len, int k) {
    int answer = 0;
    int s = 0; // 공 던진 횟수 k와 동일하면 끝
    int l = numbers_len;
    for(int i = 0; s != k; i=i+2){
        if(l%2 ==0){
            if(i+1 > l){
                i = 0;
            }
            answer = numbers[i];
            s++;
        }else if(l%2 != 0){
            if(i > l){
                i = i -l;
            }
            answer = numbers[i];
            s++;
        }
    }
    return answer;
}