#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string) {
    int length = strlen(my_string);
    int answer = 0;
    int currentnum = 0;
    char currentoperate = '+';
    for(int i = 0; i < length; i++){
        //char currentchar = my_string[i];
        if('0' <= my_string[i] && my_string[i] <= '9'){
            currentnum = currentnum * 10 + (my_string[i] -'0');
        }else if(my_string[i] == '+' || my_string[i] == '-'){
            if(currentoperate == '+'){
                answer += currentnum;
            }else if(currentoperate == '-'){
                answer -= currentnum;
            }
            currentoperate = my_string[i];
            currentnum = 0;
        }
    }
    // 맨 마지막 숫자 연산 못하는거 해결
    if(currentoperate == '+'){
        answer += currentnum;
    }else if(currentoperate == '-'){
        answer -= currentnum;
    }
    return answer;
}