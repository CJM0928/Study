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
    char* string = (char*)malloc((l+1)*sizeof(char));
    for(int i = 0; i<l; i++){
        string[i] = my_string[i];
    }
    // string배열에 넣은 문자열중 마지막은 NULL로 초기화
    string[l] = '\0';
    // ptr에 strtok함수를 함으로써 공백을 기준으로 문자열이 나누어짐
    char* ptr = strtok(string," ");
    // 나누어진 문자열이 NULL이 아니라면 계속 반복문수행
    while(ptr != NULL){
        answer[idx] = (char*)malloc((strlen(ptr)+1) * sizeof(char)); 
        strcpy(answer[idx],ptr);
        idx++;
        // ptr을 초기화 해줌으로써 다음 ptr의 문자열을 위의 반복문에 다시 적용
        ptr = strtok(NULL," ");
    }
    //마지막은 NULL로 초기화
    answer[idx] = '\0';
    return answer;
}