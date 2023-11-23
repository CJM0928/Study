#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// 각 3글자 2글자 3글자 2글자. 들어가니까 
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    for(int i = 0; i < babbling_len; i++){
        bool found = true;
        int j = 0;
        while (j < strlen(babbling[i])) {
            if (strncmp(&babbling[i][j], "aya", 3) == 0) {
                j += 3;
            } else if (strncmp(&babbling[i][j], "ye", 2) == 0) {
                j += 2;
            } else if (strncmp(&babbling[i][j], "woo", 3) == 0) {
                j += 3;
            } else if (strncmp(&babbling[i][j], "ma", 2) == 0) {
                j += 2;
            } else {
                found = false;
                break;
            }
        }
        if(found){
            answer++;
        }
    }
    return answer;
}