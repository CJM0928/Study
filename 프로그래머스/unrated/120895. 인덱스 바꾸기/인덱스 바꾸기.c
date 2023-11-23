#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int num1, int num2) {
    int l = strlen(my_string);
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* string = (char*)malloc((l+1)*sizeof(char));
    char* answer = (char*)malloc((l+1)*sizeof(char));
    strcpy(string,my_string);
    char* temp = string[num1];
    string[num1] = string[num2];
    string[num2] = temp;
    for(int i = 0; i < l; i++){
        answer[idx++] = string[i];
    }
    answer[idx] = '\0';
    return answer;
}