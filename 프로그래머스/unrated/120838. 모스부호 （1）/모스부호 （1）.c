#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* letter) {
    int l = strlen(letter);
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
                     "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
                     "-.--","--.."};
    char* answer = (char*)malloc((l+1)*sizeof(char));
    char* ptr = strtok(letter," ");
    while(ptr != NULL){
        for(int i= 0; i < 26; i++){
            if(strcmp(morse[i],ptr) == 0){
                answer[idx++] = i + 'a';
            }
        }
        ptr = strtok(NULL," "); // ptr을 포인터로 이동시켜야 다음 while 수행가능
    }
    answer[idx] = '\0';
    return answer;
}