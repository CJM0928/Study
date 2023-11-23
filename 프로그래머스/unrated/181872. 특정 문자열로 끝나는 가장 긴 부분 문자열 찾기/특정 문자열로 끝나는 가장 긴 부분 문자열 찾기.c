#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* myString, const char* pat) {
    int l = strlen(myString);
    int p_l = strlen(pat);
    int idx = 0;
    int e = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((l+1) * sizeof(char));
    for(int i = 0; i < l; i++){
            int j = i;
            int k = 0;
        if(myString[j] == pat[k]){
            while(k < p_l){
                if(myString[j] == pat[k]){
                    j++;
                    k++;
                }else{
                    break;
                }
            }
            if(k == p_l){
                e = i;
            }
        }
    }
    for(int s = 0; s < e + p_l; s++){
        answer[idx++] = myString[s];   
    }
    answer[idx] = '\0';
    return answer;
}