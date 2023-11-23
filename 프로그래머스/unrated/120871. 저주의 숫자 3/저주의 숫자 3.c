#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//예제 1은 23, 24까지 3의배수거나 3이라서 잘림.
int solution(int n) {
    int answer = 0;
    int idx = n;
    int temp = 1;
    for(int i = 1; i <= n; i++){
        while(temp % 3 == 0||temp % 10 == 3||temp / 10 == 3||temp / 10 == 13){
            temp = temp + 1;
        }
        temp = temp +1;
    }
    answer = temp -1;
    return answer;
}