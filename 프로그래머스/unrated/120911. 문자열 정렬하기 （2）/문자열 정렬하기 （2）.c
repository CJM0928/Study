#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    int l = strlen(my_string);
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((l+1)*sizeof(char));
    char* string = (char*)malloc((l+1)*sizeof(char));
    strcpy(string,my_string);
    for(int i = 0; i < l; i++){
        if('A' <= string[i] && string[i] <= 'Z'){
            string[i] = string[i] + 32;
        }
    }
    for(int i = 0; i < l-1; i++){
        for(int j = i+1; j <l; j++){
            if(string[i] > string[j]){
                char* temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    for(int i = 0; i < l; i++){
        answer[idx++] = string[i];
    }
    answer[idx] = '\0';
    return answer;
}