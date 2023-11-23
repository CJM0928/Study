#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// 테스트케이스 2는 arr1과의 값을 비교하지않음.
int solution(int arr[], size_t arr_len) {
    int l = arr_len;
    int idx = 0;
    int arr1[l];
    int s = 0;
    for(int j = 1; j < 100; j++){
        for(int i = 0; i < l; i++){
            if(arr[i] >= 50 && arr[i] % 2 == 0){
                arr[i] = arr[i] / 2;
                s++;
            }else if(arr[i] < 50 && arr[i] % 2 == 1){
                arr[i] = (arr[i] * 2) + 1;
                s++;
            }
        }
        // s++을 통해서 arr이 변하지않는 j값을 찾아준다.
        if(s == 0){
            return j - 1;
        }
        // for(int i = 0; i < l; i++){
        //     if(arr1[i] == arr[i]){
        //         s++;
        //         if(s == l){
        //             return j;
        //         }
        //     }
        // }
        s = 0;
        // for(int i = 0; i < l; i++){
        //     arr1[i] = arr[i];
        // }
    }
}