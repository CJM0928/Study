#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 유한소수 -> 2와 5가 분모여야 소수점 아래로 내려가지않는소수
// 무한소수 -> 그렇지않다면 무한소수


int solution(int a, int b) {
    int answer = 2;
    // for(int i = 1; i <= a; i++){
    //     if(a % i == 0){
    //         if(b % i ==0){
    //             a = a/i;
    //             b = b/i;
    //         }
    //     }
    // }
    while(b % 2 == 0){
        b /= 2;
    }
    while(b % 5 == 0){
        b /= 5;
    }
    // b가 1이되거나 또는 a와 같은값이 되어서 0이될때 유한소수
    if(a % b ==0){
        answer =1;
    }
    return answer;
}