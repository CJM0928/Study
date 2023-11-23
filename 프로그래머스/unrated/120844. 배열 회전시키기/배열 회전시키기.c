#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 인덱스 마지막값 + 1 % strlen(numbers) --> right
// strlen(numbers) -1  % strlen(numbers) --> left
// numbers_len은 배열 numbers의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(int numbers[], size_t numbers_len, const char* direction) {
    int n = numbers_len;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((n+1)*sizeof(int));
    for(int i = 0; i < n; i++){
        if(strcmp(direction,"right") == 0){
            answer[(i+1)% n] = numbers[i];
        }else if(strcmp(direction,"left") == 0){
            answer[(i+(n-1))% n] = numbers[i];
        }
    }
    return answer;
}