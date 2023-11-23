#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// 여기서 number는 int가 아닌 char형임
int solution(const char* number) {
    int answer = 0;
    int l = strlen(number);
    for(int i = 0; i < l; i++){
        int n = number[i] - '0'; // 문자형을 int형으로 변환
        answer += n;
    }
    answer = answer % 9;
    return answer;
}