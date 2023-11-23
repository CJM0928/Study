//isupper=소문자를 판별하는 함수
//toupper=대문자를 소문자로 변환하는 함수
//islower=대문자를 판별하는 함수
//tolower=소문자를 대문자로 변환하는 함수
#include <stdio.h>
#define LEN_INPUT 10

int main(void) {
    char s1[LEN_INPUT];
    int i = 0;
    scanf("%s", s1);
    
    while(s1[i]){
        if(isupper(s1[i])){
            s1[i] = tolower(s1[i]);    
        }
        else if (islower(s1[i])){
            s1[i] = toupper(s1[i]);
        }
        i++;    
    };

printf(s1);
return 0;
}
