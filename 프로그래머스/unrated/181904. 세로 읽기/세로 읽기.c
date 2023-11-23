#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// strcpy를 이용해서 문제풀기
// strcpy로 char** str1 만들어서 my_string[m*i] 보내기 
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int m, int c) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int l = strlen(my_string);
    // answer 할당 , str1(2차원배열 할당)
    char* answer = (char*)malloc((l+1) * sizeof(char));
    char** str1 = (char**)malloc((l/m + 1) * sizeof(char*));
    int idx = 0;
    // str1에 my_string m번째 복사
    for(int i = 0; i < l/m; i++){
        str1[i] = (char*)malloc((l+1) * sizeof(char));
        strcpy(str1[i],&my_string[m*i]);
    }
    // str1의 [i][c-1] 자리마다 answer에 입력 <== 얘 때문에 char** st1 할당한것
    for(int i = 0; i< l/m; i++){
        answer[idx++] = str1[i][c-1];
    }
    // answer의 idx 값 초기화
    answer[idx] = '\0';
    return answer;
}