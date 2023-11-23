#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr1_len은 배열 arr1의 길이입니다.
// arr2_len은 배열 arr2의 길이입니다.
int solution(int arr1[], size_t arr1_len, int arr2[], size_t arr2_len) {
    int arr11 = 0;
    int arr22 = 0;
    if(arr1_len > arr2_len){
        return 1;
    }else if(arr1_len < arr2_len){
        return -1;
    }
    if(arr1_len == arr2_len){
        for(int i = 0; i < arr1_len; i++){
            arr11 = arr11 + arr1[i];
            arr22 = arr22 + arr2[i];
        }
        if(arr11 > arr22){
            return 1;
        }else if(arr22 > arr11){
            return -1;
        }else if(arr11 == arr22){
            return 0;
        }
    }
}