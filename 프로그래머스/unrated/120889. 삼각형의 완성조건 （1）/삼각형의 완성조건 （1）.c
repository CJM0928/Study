#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sides_len은 배열 sides의 길이입니다.
int solution(int sides[], size_t sides_len) {
    int answer = 2;
    int l = sides_len;
    for(int i = 0; i < l-1; i++){
        for(int j = i+1; j < l; j++){
            if(sides[i] > sides[j]){
                int temp = sides[i];
                sides[i] = sides[j];
                sides[j] = temp;
            }
        }
    }
    if(sides[0] + sides[1] > sides[2]){
        answer = 1;
    }
    return answer;
}