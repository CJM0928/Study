#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// strArr_len은 배열 strArr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* strArr[], size_t strArr_len) {
    int l = strArr_len;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    // 이차원 배열(문자열 배열)의 경우 처음에 한번 동적할당해줌.
    char** answer = (char**)malloc((l + 1) * sizeof(char*));
    for (int i = 0; i < l; i++) {
        // for문 들어오면서 해당 주소에 문자열 길이 만큼의 메모리 할당해줌.
        int row_l = strlen(strArr[i]);
        answer[i] = (char*)malloc(row_l + 1);
        if (i % 2 != 0) {
            for (int j = 0; j < row_l; j++) {
                if (strArr[i][j] >= 97) {
                    answer[i][j] = strArr[i][j] - 32;
                }else{
                    answer[i][j] = strArr[i][j];
                }
            }
        }
        else if (i % 2 == 0) {
            for (int k = 0; k < row_l; k++) {
                if (strArr[i][k] < 97) {
                    answer[i][k] = strArr[i][k] + 32;
                }else{
                    answer[i][k] = strArr[i][k];
                }
            }
        }
        answer[i][row_l] = '\0';
    }
    // for(int i=0; i<l; i++){
    //     answer[idx++] = str[i];
    // }
    // answer[idx] = '\0';
    // return answer;
    answer[l] = '\0';
    return answer;
}