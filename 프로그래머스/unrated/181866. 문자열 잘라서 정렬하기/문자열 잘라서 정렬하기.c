#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// strtok을 통해 x기준으로 문자열을 자른다.
// 만약 x가 여러개일경우 " "이 발생하는데 이건 조건문으로 해결
// strcmp를통해서 사전순으로 정렬한다
char** solution(const char* myString) {
    int l = strlen(myString);
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc((l + 1) * sizeof(char*));
    char** str1 = (char**)malloc((l + 1) * sizeof(char*));
    char* string = (char*)malloc((l + 1) * sizeof(char));
    for (int i = 0; i < l; i++) {
        string[i] = myString[i];
    }
    string[l] = '\0';
    char* ptr = strtok(string, "x");
    // ptr에 x기준으로 나눠진 값들을 str1에 복사
    while (ptr != NULL) {
        str1[idx] = (char*)malloc((strlen(ptr) + 1) * sizeof(char));
        strcpy(str1[idx], ptr);
        // str1의 인덱스값이 NULL이 아닌경우 answer 인덱스에 복사
        // 인덱스 값이 " " 경우를 방지. 
        if (str1[idx] != NULL) {
            answer[idx] = str1[idx];
            idx++;
        }
        ptr = strtok(NULL, "x");
    }
    // strcmp 활용해서 사전순으로 정렬하는 방식
    for(int i = 0; i < idx -1; i++){
        for(int j = i+1; j < idx; j++){
            if(strcmp(answer[i] , answer[j]) > 0){
                char* temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }
    return answer;
}