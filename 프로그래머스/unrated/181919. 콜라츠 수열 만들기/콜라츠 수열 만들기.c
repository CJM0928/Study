#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * (n + 1));
    int index = 0;
    answer[index++] = n;
    while(n != 1){
        if(n % 2 == 0){
            n = n/2;
        }else if(n % 2 != 0){
            n = (3 * n) + 1;
        }
        answer[index++] = n;
    }
    return answer;
}