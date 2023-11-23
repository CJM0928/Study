#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// "a","b","c"를 구분자로 사용한다 -> "abc"로 해도 된다.
char** solution(const char* myStr) {
    int l = strlen(myStr);
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc((l+1)*sizeof(char*));
    char* ptr = strtok(myStr,"abc");
    while(ptr != NULL){
        answer[idx] = (char*)malloc((strlen(ptr)+1)*sizeof(char));
        strcpy(answer[idx],ptr);
        idx++;
        ptr = strtok(NULL,"abc");
    }
    if(answer[idx] == NULL){
        answer[idx] = "EMPTY";
    }
    return answer;
}