#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// indices_len은 배열 indices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int indices[], size_t indices_len) {
    int l = strlen(my_string);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((l+1)*sizeof(char));
    char* str = (char*)malloc((l+1)*sizeof(char));
    char* temp = (char*)malloc((l+1)*sizeof(char));
    strcpy(str,my_string);
    for(int i = 0; i < l; i++){
        for(int j = 0; j < indices_len; j++){
            int n = indices[j];
            str[n] = ' ';
        }
    }
    int index = 0;
    for(int i = 0; i < l; i++){
        if(str[i] != ' '){
            answer[index++] = str[i];
        }
    }
    answer[index] = '\0';
    return answer;
}