#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// atoi는 문자열 전체를 정수로 변환하는 함수
// 각 i인덱스에 - '0'을 활용하자. 
// 여기서 '0'은 문자인 num_str[i]을 정수로 변환시켜준다. 
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* num_str) {
    int answer = 0;
    int l = strlen(num_str);
    for(int i =0; i <l ; i++){
        int n = num_str[i] - '0';
        answer += n;
    }
    return answer;
}