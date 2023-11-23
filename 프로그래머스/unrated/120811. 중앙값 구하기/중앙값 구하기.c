#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    int l = array_len;
    // 선택정렬로 값을 크기에따라 재정렬한다.
    for(int i = 0; i < l - 1; i++){
        for(int j = i+1; j < l; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    //정렬 후, 중간인덱스의 값을 answer에 입력한다.
    answer = array[array_len/2];
    return answer;
}