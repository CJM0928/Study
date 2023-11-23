#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// str_list_len은 배열 str_list의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// 배열을 리턴하는게아니라 문자열을 리턴해야하므로 strcat을 사용한다.
// strcat은 문자열 합치기
// 테스트케이스 6번만 붙는이유는 배열의 길이와 원소의 길이가 같아서.
// 그렇다면 str_list의 각 원소길이들을 합하고 answer에 할당하면?
// 추가적으로 str_list의 원소값들을 answer의 각 주소(idx)에 strcpy를 한다면?
char* solution(const char* str_list[], size_t str_list_len, const char* ex) {
    int l = str_list_len;
    size_t length = 0;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    for(int i = 0; i < l; i++){
        length += strlen(str_list[i]);
    }
    char* answer = (char*)malloc((length+1)*sizeof(char));
    for(int i = 0; i <l; i++){
        char* ptr = strstr(str_list[i],ex);
        if(ptr == NULL){
            size_t length1 = strlen(str_list[i]);
            strcpy(answer + idx,str_list[i]); // answer가 100번지라면 idx를 더한 번지에
            // str_list[i]값을 복사 
            idx += length1;
        }
    }
    answer[idx] = '\0';
    return answer;
}