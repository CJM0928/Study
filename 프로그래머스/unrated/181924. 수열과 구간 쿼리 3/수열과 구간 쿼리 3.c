#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
//queries 를 [i,j]로 이해하고 진행
int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int i;
    int j;
    int temp;
    int* answer = (int*)malloc((arr_len +1) * sizeof(int));
    for(int k = 0; k < queries_rows; k++){
      i = queries[k][0];
      j = queries[k][1];
        
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return arr;
}