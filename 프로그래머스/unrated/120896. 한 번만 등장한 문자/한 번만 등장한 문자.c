#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 소문자로 이루어져있으니 총 26개의 인덱스만 있으면된다.
// - 'a'를 통해서 정수화 시켜 임시배열의 인덱스에 넣는다.
// 그 인덱스가 1일때는 answer에 입력하지않는다. 0일때만 입력
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    int l = strlen(s);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((l+1)*sizeof(char));
    int* temp =(int*)malloc((26)*sizeof(int)); 
    int idx = 0;
    for(int i = 0; i < 26; i++){
        temp[i] = 0;
    }
    for(int i=0; i < l; i++){
        temp[s[i] - 'a']++;
    }
    for(int i=0; i <l; i++){
        if(temp[s[i]-'a'] == 1){
            answer[idx++] = s[i];
        }
    }
    for(int i = 0; i < idx-1; i++){
        for(int j = i+1; j < idx; j++){
            if(answer[i] > answer[j]) {
                char c = answer[i];
                answer[i] = answer[j];
                answer[j] = c;
            }
        }
    }
    answer[idx] = '\0';
    return answer;
}