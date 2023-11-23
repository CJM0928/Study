#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1부터 계속 곱해서 n과 같은 값이 나오면 i룰 answer로 하고
// n보다 커져서 정확한값이 떨어지지않는다면, n 이하의 최대 i값을 answer한다.

int solution(int n) {
    int answer = 0;
    int temp = 1;
    for(int i = 1; i <= n; i++){
        temp *= i;
        if(temp == n){
            answer = i;
            break;
        }
        if(temp > n){
            answer = i -1;
            break;
        }
    }
    return answer;
}