#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* code) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int length = strlen(code);
    char* answer = (char*)malloc((length * sizeof(char)) + 1);
    int idx = 0;
    int mode = 0; // 모드는 0 or 1 기본값은 0으로
    for(int i = 0; i < length; i++){
        if(mode == 0 && code[i] == '1'){
            mode = 1;
        }else if(mode == 0 && i % 2 == 0){
            answer[idx++] = code[i];
        }else if(mode == 1 && code[i] == '1'){
            mode = 0;
        }else if(mode == 1 && i % 2 != 0){
            answer[idx++] = code[i];
        }
    }
    answer[idx] = '\0';
    if(idx == 0){
        answer = (char*)malloc(6);
        strcpy(answer, "EMPTY"); 
    }
    return answer;
}
int main() {
    char* code;
    scanf("%s", code);
    int l = strlen(code);
    if (l <= 100000) 
    {
        char* result = solution(code);
        printf("%s", result);
        free(result);
    }
    else {
        printf("제한 사항을 초과한 길이의 입력값을 받았습니다.");
    }
    return 0;
}