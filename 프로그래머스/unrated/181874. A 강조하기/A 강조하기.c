#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* myString) {
    int l = strlen(myString);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((l + 1) * sizeof(char));
    for(int i = 0; i<l; i++){
        if(myString[i] == 'a'){
            answer[i] = myString[i] - 32;
        }else if(myString[i] == 'A'){
            answer[i] = myString[i];
            continue;
        }else if(myString[i] >= 'B' && myString[i] <= 'Z'){
            answer[i] = myString[i] + 32;
        }else if(myString[i] >= 'b' && myString[i] <= 'z'){
            answer[i] = myString[i];
            continue;
        }else if(myString[i] == ' '){
            answer[i] = myString[i];
            continue;
        }
    }
    answer[l] = '\0';
    return answer;
}