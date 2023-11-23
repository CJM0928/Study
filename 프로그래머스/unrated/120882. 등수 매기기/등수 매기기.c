#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_rows는 2차원 배열 score의 행 길이, score_cols는 2차원 배열 score의 열 길이입니다.
int* solution(int** score, size_t score_rows, size_t score_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    // 나눌때 소수점도 고려해줘야 하기때문에 scoreAdd는 double형으로 선언
    int* answer = (int*)malloc((score_rows + 1)*sizeof(int));
    double* scoreAdd = (double*)malloc((score_rows + 1)*sizeof(double));
    // score 값 합치고 나누기
    for(int i = 0; i < score_rows; i++){
        scoreAdd[i] = 0.0;
        for(int j = 0; j < score_cols; j++){
            scoreAdd[i] += (double)score[i][j];
        }
        scoreAdd[i] /= score_cols;
    }
    // 등수 만들기
    for(int i = 0; i < score_rows; i++){
        answer[i] = 1;
        for(int j = 0; j < score_rows; j++){
            if(i == j){
                continue;
            }
            if(scoreAdd[i] == scoreAdd[j]){
                continue;
            }else if(scoreAdd[i] < scoreAdd[j]){
                answer[i]++;
            }
        }
    }
    return answer;
}