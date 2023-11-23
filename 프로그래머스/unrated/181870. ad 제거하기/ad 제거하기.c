#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// strArr_len은 배열 strArr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// 내 계획은 strstr을 활용, "ad"문자열이 존재하는 배열의 문자열은 
// 문자열[i] = 문자열의[i+1] 이런 방식의 반복문으로 주소i의 문자열을 지워본다.
char** solution(const char* strArr[], size_t strArr_len) {
    int l = strArr_len;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc((l+1)*sizeof(char*));
    char** str1 = (char**)malloc((l+1)*sizeof(char*));
    //strcpy 할때 제대로 동적할당이 안됨
    for(int i = 0; i <l; i++){
        str1[i] = strArr[i];
    }
    for(int i = 0; i < l ; i++){
        char* ptr = strstr(str1[i],"ad");
        // if(ptr != NULL){
        //     answer[idx++] = str1[i+1];
        //     idx--;
        // }
        if(ptr == NULL){
            answer[idx++] = str1[i];
        }
    }
    // for(int i = 0; i<l; i++){
    //     answer[idx++] = str1[i];
    // }
    answer[idx] = '\0';
    return answer;
}