#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* myString, const char* pat) {
    int l = strlen(myString);
    char* str1 = (char*)malloc((l + 1) * sizeof(char));
    strcpy(str1,myString);
    for(int i =0; i<l; i++){
        if(myString[i] == 'A'){
            str1[i] = 'B';
        }else if(myString[i] == 'B'){
            str1[i] = 'A';
        }
    }
    char* ptr = strstr(str1 , pat);
    if(ptr != NULL){
        return 1;
    }else{
        return 0;
    }
}