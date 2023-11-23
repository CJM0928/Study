#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 접미사는 문자열 맨 끝이 나타나는 부분
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string, const char* is_suffix) {
    int my_l = strlen(my_string);
    int is_l = strlen(is_suffix);
    //문자열 길이 비교
    if(my_l < is_l){
        return 0;
    }
    //접미사 비교
    for(int i = 1; i <= is_l; i++){
        if(my_string[my_l - i] != is_suffix[is_l - i]){
            return 0;
        }
    }
    return 1;
}