#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// % 해서 k가 남을때 answer에 +1을 해준다.
int solution(int i, int j, int k) {
    int answer = 0;
    for(int n = i; n <= j; n++){
        int temp = n;
        while(temp > 0){
            if(temp % 10 == k){
                answer++;
            }
            temp /= 10;
        }
    }
    return answer;
}