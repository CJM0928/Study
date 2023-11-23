#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num, int k) {
    int answer = 0;
    int s = 1;
    int j = 0;
    while(num > 0){
        int n = num % 10;
        if(n == k){
            j = s;
        }
        num = num / 10;
        s++;
    }
    answer = s - j;
    if(j == 0){
        answer = -1;
    }
    return answer;
}