#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 부피를 구해서 부피 / 부피를 하는 문제가 아니다.
// 이유는 주사위는 상자와 평행하게 넣기때문

// box_len은 배열 box의 길이입니다.
int solution(int box[], size_t box_len, int n) {
    box[0] /= n;
    box[1] /= n;
    box[2] /= n;
    int answer = 1;
    for(int i = 0; i < box_len; i++){
        answer *= box[i];
    }
    return answer;
}