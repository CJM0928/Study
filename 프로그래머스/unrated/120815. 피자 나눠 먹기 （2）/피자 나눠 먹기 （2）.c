#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int p = 0;
    int i = 1;
    while(1){
        p = 6 * i;
        if(p % n == 0){
            break;
        }else{
            i++;
        }
    }
    answer = p/6;
    return answer;
}