#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// sides_len은 배열 sides의 길이입니다.
// 만약 주어진 값중에서 제일큰값이 제일 긴변이면 작은값~긴변까지가 삼각형 만들어지는 조건
// 주어지지않은값이 제일 길다면 두 값을 더한값보다 작은값이 제일 긴변.
int solution(int sides[], size_t sides_len) {
    int answer = 0;
    int big = 0;
    int small = 0;
    if(sides[0] >= sides[1]){
        big = sides[0];
        small = sides[1];
    }else if(sides[0] < sides[1]){
        big = sides[1];
        small = sides[0];
    }
    int n= (big-small)+1;
    //긴변이 big인경우
    for(int i = n; i <= big; i++){
        if(small + n > big){
            answer++;
        }
    }
    // 나머지 한 변이 가장 긴변인경우
    int bigbig = big+small;
    for(int i = big+1; i < bigbig; i++){
        answer++;
    }
    return answer;
}