#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
// x좌표 정렬 y좌표 정렬 후
// x 제일큰값 - 제일작은값 y제일큰값 - y제일작은값 나온걸 기준으로
// 곱해준다.
// a와 b는 dots[0]의 주소들 ex: dots[0]이 100번지 라면 101번지 102번지 등등
// a와 b를 더해서 비교해서 양수로 나오면 정렬수행 , a = b 또는 음수로 나오면 정렬수행x
// *(int *)a 는 void* a를 참조한거고
// *(int **)a 는 compareX나 Y의 것을 참조
// 주소를 가져오는거라 아래가 맞다.
int compareX(const void* a,const void* b){
    int* pointA = *(int**)a;
    int* pointB = *(int**)b;
    
    return pointA[0] - pointB[0];
}

int compareY(const void* a,const void* b){
    int* pointA = *(int**)a;
    int* pointB = *(int**)b;
    
    return pointA[1] - pointB[1];
}

int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    //x 좌표 기준 정렬
    int answer = 0;
    qsort(dots,dots_rows,sizeof(int*),compareX);
    
    //y 좌표 기준 정렬
    qsort(dots,dots_rows,sizeof(int*),compareY);
    
    int width = dots[dots_rows -1][0] - dots[0][0];
    int height = dots[dots_rows -1][1] - dots[0][1];
    answer = width * height;
    return answer;
}