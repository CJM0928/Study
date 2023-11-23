#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
// queries [s,e,k]
// arr[i]
// s <= i <= e 모든 i에대해 k보다 크면서 가장작은 arr[i] 찾기
// arr[i]의경우 
//0 <= i <= 4 모든 0에대해 2보다 크면서 가장작은 arr[i] 찾기
int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    // 테스트 3 〉실패 (signal: aborted (core dumped))
    // answer 의 크기 이슈 : sizeof(int*)로 수정하여 해결
    // 테스트 7 실패 (signal: segmentation fault (core dumped))
    // answer에 arr_len 대신 queries_rows 크기를 할당해줘야한다.
    // 이유는 answer는 queries_row 길이만큼 출력할것이기 때문이며, arr_len을 하면
    // 세그먼트 오류가 뜬다
    int* answer = (int*)malloc((sizeof(int*) * queries_rows)+1);
    for(int j = 0; j < queries_rows; j++){
        int s = queries[j][0];
        int e = queries[j][1];
        int k = queries[j][2];
        int min = 1000001; // 원소값이 1000000까지 가능하니까 +1해줌
                           // arr배열에서 k보다 크지만 그중에서 가장 작은값
        for(int a = s; a <= e; a++){
            if(arr[a] > k && arr[a] < min){
                min = arr[a];
            }
        }
        if(min == 1000001) //원소값이 1000000까지 가능하니까 +1해줌
        {
            answer[j] = -1;
        }else{
            answer[j] = min;
        }
    }
    answer[queries_rows] = 0;
    return answer;
}