#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lines_rows는 2차원 배열 lines의 행 길이, lines_cols는 2차원 배열 lines의 열 길이입니다.
// start , end 두개는 기준에서 제외 start < i <= end 두고 i가 들어간 범위의 값을count++ 해준다.
// -> 이걸 두개로 나눠서 start < i && i <= end 로 하면 어떨까
// 예시 3 기준 겹치는 선 4,5 // 2,3 // 6,7,8,9
// 길이,원소길이 고정 -> 0 -> 1 ,0 -> 2 // 1 -> 2 이렇게 3번 간다고 한다.
// 3개를 다 놓고 i에 포함되서 count 시키고, count가 2,3개일때 answer ++ 한다.
// 두개이상의 겹치는 부분의 길이이기때문에 
int solution(int** lines, size_t lines_rows, size_t lines_cols) {
    int answer = 0;
    int count = 0;
    for(int i = -100; i <= 100; i++){
        count = 0;
        if((lines[0][0] < i) && (i <= lines[0][1])){
            count++;
        }
        if((lines[1][0] < i) && (i <= lines[1][1])){
            count++;
        }
        if((lines[2][0] < i) && (i <= lines[2][1])){
            count++;
        }
        if(count > 1){
            answer++;
        }
    }
    return answer;
}