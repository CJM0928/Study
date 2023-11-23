#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// strstr 함수를 사용하자!
// char* strstr(char* str1, const char* str2);
// strstr은 str1에서 str2와 일치하는 문자열이 있는지 확인을 하는 함수
// 대소문자를 구별하지 않기때문에 +- 32로 대문자나 소문자로 통일 해줄것
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(char* myString, char* pat) {
    int my_l = strlen(myString);
    int pat_l = strlen(pat);
    if(pat_l > my_l){
        return 0;
    }
    for(int i = 0; i <my_l; i++){
        if(myString[i] >= 97){
            myString[i] = myString[i] - 32;
        }
    }
    for(int j = 0; j < pat_l; j++){
        if(pat[j] >= 97){
            pat[j] = pat[j] - 32;
        }
    }
    char ptr = strstr(myString, pat);
    if(ptr != NULL){
        return 1;
    }else if(ptr == NULL){
        return 0;
    }
}