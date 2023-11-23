#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int s = 0;
    for(int i= 1; i <= n; i++){
        s = 0;
        for(int j = 1; j <= i; j++){
            if(i%j==0){
                s++;
            }
        }
        if(s >= 3){
            answer++;
        }
    }
    return answer;
}