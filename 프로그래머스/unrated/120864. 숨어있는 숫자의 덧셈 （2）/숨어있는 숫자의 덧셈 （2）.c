#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// 숫자를 발견하면 n에 저장한다. 그 다음 문자가 자연수가아니라면 n은 answer에 저장 후 다시 0으로 초기화하고
// 다음숫자를 발견하면 n에 저장 그러다가 연속으로 숫자가 나온다면 n을 10을 곱하고 이어간다.
// 다음 문자를 발견할때까지

int solution(const char* my_string) {
    int answer = 0;
    int l = strlen(my_string);
    int n = 0;
    for(int i = 0; i < l; i++){
        if('0' <= my_string[i] && my_string[i] <= '9'){
            n = n * 10 + (my_string[i] - '0');
        }else{
            answer += n;
            n = 0;
        }
    }
    answer += n; // my_string의 마지막 인덱스가 숫자인경우 answer에 n값을 입력해준다.
    return answer;
}