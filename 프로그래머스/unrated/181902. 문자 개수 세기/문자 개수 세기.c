#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* my_string) {
    int index = 0;
    int l = strlen(my_string);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(52 * sizeof(int));
    // 문자 배열 초기화 // 만약 실행결과 앞에 쓰레기값이 나온다면 사용하는 방법
    for (int i = 0; i < 52; i++) {
        answer[i] = 0;
    }
    // 대문자 개수 찾기
    for(int i = 0; i < l; i++){
        for(int j = 0; j < 26; j++){
            if(my_string[i] == 'A' + j){
                answer[j]++;
            }
        }
    }
    //소문자 개수찾기
    for(int i = 0; i < l; i++){
        for(int j = 0; j < 26; j++){
            if(my_string[i] == 'a' + j){
                answer[j+26]++;
            }
        }
    }
    return answer;
}