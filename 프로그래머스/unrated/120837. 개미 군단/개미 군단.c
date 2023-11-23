#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int hp) {
    int answer = 0;
    int s = 0;
    s = s + (hp / 5);
    hp = hp % 5;
    
    if(hp == 0){
        answer = s;
        return answer;
    }
   
    s = s + (hp / 3);
    hp = hp % 3;
    if(hp == 0){
        answer = s;
        return answer;
    }
    
    s = s + (hp / 1);
    hp = hp % 1;
    answer = s;
    return answer;
}