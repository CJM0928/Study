#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
// array의 인덱스의 값이 n보다 작으면 빼서 나온 값
// 반대로 크다면 빼서 나온 값(절대값)
// 이 값을 임시 temp[idx] 에 저장해서 제일 가까운수 (차이가 작은수)의 인덱스의 값을 출력한다.
// 만약 같은값이 2개면은 n값보다 작은 인덱스의 값을 출력.
// int abs(int a,int b){
//     b = b - a;
//     if(b < 0){
//         return b;
//     }
//     return b;
// }
int solution(int array[], size_t array_len, int n) {
    int answer = 0;
    int l = array_len;
    int idx = 0;
    int temp[l];
    int k = 0;
    int min_value = 0;
    for(int i = 0; i < l; i++){
        int j = array[i];
        if(array[i] > n){
            j = n - j;
            temp[idx++] = abs(j); 
        }else if(array[i] <= n){
            temp[idx++] = n - j;
        }
    }
    int min = 9999;
    for(int i = 0; i < l; i++){
        if(temp[i] < min){
            min = temp[i];
            k = i;
        }
    }
    min_value = array[k]; // 값이 여러개일경우를 확인해보기위한 변수
    for(int i = 0; i < l; i++){
        if(temp[i] == min && array[i] < min_value){
            min_value = array[i];
            k = i;
        }
    }
    answer = array[k];
    return answer;
}