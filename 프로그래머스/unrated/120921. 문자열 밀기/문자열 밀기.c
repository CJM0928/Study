#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// strcmp로 비교해서 비교안되면 answer++;
// 비교되면 answer++; 후 break; 출력
int solution(const char* A, const char* B) {
    int length = strlen(A);
    char* String = (char*)malloc((length+1)*sizeof(char));
    int count = 0;
    int answer = 0;
    strcpy(String,A);
    if(strcmp(String,B)==0){
            return 0;
    }
    
    for(int i = 0; i < length; i++){
        
        char last_word = String[length-1];
        for(int j = length-1 ; j > 0; j--){
            String[j] = String[j-1];    
        }
        String[0] = last_word;
        count++;
        
        if(strcmp(String,B)==0){
            answer = count;
            return answer;
        }
    }
    
    if(count == length){
        return -1;
    }
}