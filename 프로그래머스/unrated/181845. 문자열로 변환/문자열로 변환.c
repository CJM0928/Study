#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//정수를 문자열로 --> sprintf 활용
// sprintf(문자열,%형태,정수);

char* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((n+1)*sizeof(char));
    sprintf(answer,"%d",n);
    return answer;
}