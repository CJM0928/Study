#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    int l = strlen(my_string);
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc((l+1)*sizeof(char*));
    char** str1 = (char**)malloc((l+1)*sizeof(char*));
    char* string = (char*)malloc((l+1)*sizeof(char));
    for(int i = 0; i<l; i++){
        string[i] = my_string[i];
    }
    string[l] = '\0';
    char* ptr = strtok(string," ");
    while(ptr != NULL){
        str1[idx] = (char*)malloc((strlen(ptr)+1) * sizeof(char));
        answer[idx] = (char*)malloc((strlen(ptr)+1) * sizeof(char));
        strcpy(str1[idx],ptr);
        if(str1[idx] != NULL){
            answer[idx] = str1[idx];
            idx++;
        }
        ptr = strtok(NULL," ");
    }
    answer[idx] = '\0';
    return answer;
}