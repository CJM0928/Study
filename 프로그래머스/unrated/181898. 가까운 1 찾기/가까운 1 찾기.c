#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// arr의 값이 1인 인덱스가 idx보다 크지만 그중에서 가장 작은값을 출력
int solution(int arr[], size_t arr_len, int idx) {
    int answer = 0;
    int min = 100001;
    for(int i = 0; i < arr_len; i++){
        if(arr[i] == 0){
            continue;
        }else if(arr[i] == 1){
            if(i >= idx){
                if(min > i){
                    min = i;
                }
            }else{
                continue;
            }
        }
    }
    answer = min;
    if(min == 100001){
        answer = -1;
    }
    return answer;
}