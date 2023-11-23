#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
// 가장 많이 나온 숫자가 몇번나왔는지가 아니라
// 가장 많이 나온 숫자를 찾는 문제다.
int solution(int array[], size_t array_len) {
    int answer = 1;
    int l = array_len;
    //int* aray = (int*)malloc(1001 *sizeof(int));
    int aray[1001] = {0};
    int max = 0;
    int count = 0;
    for(int i = 0; i < l; i++){
        int n = array[i];
        aray[n]++; 
        if(max < aray[n]){
            max = aray[n];
            answer = n;
        }
    }
    for(int i = 0; i < 1001; i++){
        if(aray[i] == max){
            count++;
            if(count > 1){
            return -1;
            }
        }
    }
    return answer;
}