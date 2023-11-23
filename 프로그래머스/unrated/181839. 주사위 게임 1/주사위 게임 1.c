#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// int abs(int a, int b){
//     a = a - b;
//     if(a < 0){
//         return -a;
//     }
//     return a;
// }

int solution(int a, int b) {
    int answer = 0;
    if(a % 2 == 1 && b % 2 == 1){
        answer = pow(a,2) + pow(b,2);
    }else if(a % 2 == 1 || b % 2 == 1){
        answer = 2 * ( a + b );
    }else if(a % 2 == 0 && b % 2 == 0){
        answer = abs(a - b);
    }
    
    return answer;
}