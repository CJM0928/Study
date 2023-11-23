#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

// 문자열의 자연수는 0~9까지 있으니 0~10이라고하면 원하는 값이 나오지않는다.
int solution(const char* my_string) {
    int answer = 0;
    int l = strlen(my_string);
    for(int i = 0; i < l; i++){
        if('0' <= my_string[i] && my_string[i] <= '9'){
            answer += my_string[i] - '0';
        }
    }
    return answer;
}