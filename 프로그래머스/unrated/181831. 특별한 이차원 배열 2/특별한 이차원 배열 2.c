#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_rows는 2차원 배열 arr의 행 길이, arr_cols는 2차원 배열 arr의 열 길이입니다.
int solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int l =arr_rows ;
    int ll = arr_cols;
    int answer = 1;
    for(int i = 0; i <l; i++){
        for(int j =0; j < ll; j++){
            if(arr[i][j] == arr[j][i]){
                continue;
            }else{
                answer = 0;
                break;
            }
        }
    }
    return answer;
}