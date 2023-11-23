#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* rsp) {
    int l = strlen(rsp);
    int idx = 0 ;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((l+1)*sizeof(char));
    for(int i = 0 ; i < l; i++){
        if(rsp[i] == '2'){
            answer[idx++] = '0';
        }else if(rsp[i] == '0'){
            answer[idx++] = '5';
        }else if(rsp[i] == '5'){
            answer[idx++] = '2';
        }
    }
    answer[idx] = '\0';
    return answer;
}