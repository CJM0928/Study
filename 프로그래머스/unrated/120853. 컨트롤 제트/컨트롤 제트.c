#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int num(const char* str){
    int result = 0;
    int i = 0;
    int sign = 1;
    
    if(str[0] == '-'){
        i = 1;
        sign = -1;
    }
    
    while(str[i] != '\0'){
        if('0' <= str[i] && str[i] <= '9'){
            result = result * 10 + (str[i] - '0');
        }
        i++;
    }
    return sign * result;
}

int solution(const char* s) {
    int l = strlen(s);
    int answer = 0;
    int idx = 0 ;
    int n = 0;
    int* string =(int*)malloc((l+1)*sizeof(int));
    char* ptr = strtok(s," ");
    while(ptr != NULL){
        if(strcmp(ptr,"Z") == 0){
            answer -= string[--idx];
            n = string[idx - 1];
        }else{
            n = num(ptr);
            answer += n;
            string[idx++] = n;
        }
        ptr = strtok(NULL," ");
    }
    return answer;
}