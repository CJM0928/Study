#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_rows는 2차원 배열 arr의 행 길이, arr_cols는 2차원 배열 arr의 열 길이입니다.
int** solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int temp = 0;
    int temp1 = 1;
    if(arr_rows >= arr_cols){
        temp = arr_rows;
        temp1 = arr_rows;
    }else if(arr_rows < arr_cols){
        temp = arr_cols;
        temp1 = arr_cols;
    }
    int** answer = (int**)malloc(((temp*temp1)+1)*sizeof(int*));
    for(int i = 0; i < temp; i++){
        answer[i] =(int*)malloc((temp1+1)*sizeof(int));
        for(int j = 0; j < temp1; j++){
            answer[i][j] = 0;
        }
    }
    for(int i= 0; i < arr_rows; i++){
        for(int j =0; j < arr_cols; j++){
            answer[i][j] = arr[i][j];
        }
    }
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    return answer;
}