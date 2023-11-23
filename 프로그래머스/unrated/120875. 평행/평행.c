#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.

// 평행인 조건 y = mx + n,y = m'x + n' -> m = m' // n != n'
// 기울기는 같고, y절편은 다르다
int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    float x1 = dots[0][0], y1 =dots[0][1];
    float x2 = dots[1][0], y2 =dots[1][1];
    float x3 = dots[2][0], y3 =dots[2][1];
    float x4 = dots[3][0], y4 =dots[3][1];
    
    //길이는 4이므로 0 -> 1,2,3 // 1 -> 2,3 // 2 -> 3 6번
    float a = (y2-y1) / (x2-x1);
    float b = (y3-y1) / (x3-x1);
    float c = (y4-y1) / (x4-x1);
    float d = (y3-y2) / (x3-x2);
    float e = (y4-y2) / (x4-x2);
    float f = (y4-y3) / (x4-x3);
    
    if(a == f){
        return 1;
    }
    if(b == e){
        return 1;
    }
    if(c == d){
        return 1;
    }
    return 0;
}