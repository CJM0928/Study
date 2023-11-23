#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr의 배열에 2의값이 있는지 개수를 확인,
// 1개면은 2만출력
// 없다면 -1을출력
// 여러개라면 첫 인덱스부터 끝 인덱스까지 다 출력

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((arr_len + 1) * sizeof(int));
    int min = 100001;
    int max = 0;
    int arr_2 = 0;
    int idx = 0;
    for(int i = 0; i < arr_len; i++){
        if(arr[i] == 2){
            arr_2++;
        }
    }
    if(arr_2 > 1){
        for(int i = 0; i < arr_len; i++){
            if(arr[i] == 2){
                max = i;
                if(min > i){
                    min = i;
                }
            }
        }
        for(int i = min; i <= max; i++){
            answer[idx++] = arr[i];
        }
    }
    if(arr_2 == 0){
        answer[idx++] = -1;
    }
    if(arr_2 == 1){
        for(int i = 0; i < arr_len; i++){
            if(arr[i] == 2){
                answer[idx++] = 2;
            }
        }
    }
    return answer;
}