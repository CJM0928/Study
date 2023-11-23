#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// str_list_len은 배열 str_list의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// const char* str_list[]은 문자열을 가지고있는 배열
// "u"는 [0][0] 의 값
// 그다음 "u"은 [1][0] 의 값
// "l"은 [2][0]의 값으로 이해하면된다.
char** solution(const char* str_list[], size_t str_list_len) {
    int l = str_list_len;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc((l+1)*sizeof(char*));
    for(int i = 0; i < l; i++){
        if(str_list[i][0] == 'l'){
            for(int j = 0; j < i; j++ ){
                answer[idx++] = str_list[j];
            }
            break;
        }else if (str_list[i][0] == 'r'){
            for(int k = i; k < l; k++){
                answer[idx++] = str_list[k+1];
            }
            break;
        }
    }
    return answer;
}