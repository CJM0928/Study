#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 핫/아이스 아메리카노 4500원
// 핫/아이스 카페라테 5000원
// 아무거나 아메리카노로 통일
// order_len은 배열 order의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* order[], size_t order_len) {
    int l = order_len;
    int answer = 0;
    for(int i = 0; i<l; i++){
        char* ptr = strstr(order[i],"cafe");
        if(ptr != NULL){
            answer += 5000;
        }else{
            answer += 4500;
        }
    }
    return answer;
}