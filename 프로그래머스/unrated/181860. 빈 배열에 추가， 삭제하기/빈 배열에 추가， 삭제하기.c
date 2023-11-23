#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// arr_len은 배열 arr의 길이입니다.
// flag_len은 배열 flag의 길이입니다.
int* solution(int arr[], size_t arr_len, bool flag[], size_t flag_len) {
    int idx = -1;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(10001 * sizeof(int));
    for(int i = 0; i < arr_len; i++){
        int n = arr[i];
        if(flag[i] == true){
            for(int j = 0; j < n*2; j++){
                answer[++idx] = n;
            }
            //idx--;
        }else if(flag[i] == false){
            for(int k = 0; k <n; k++){
                answer[idx--] = '\0';
                //idx--;
            }
            //idx++;
        }
    }
    return answer;
}