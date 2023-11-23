#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//strcpy, atoi 사용할것
//문자열 배열을 받아서 atoi로 변환하여 k값과 비교하여 answer으로 출력
// intStrs_len은 배열 intStrs의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* intStrs[], size_t intStrs_len, int k, int s, int l) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((intStrs_len +1 ) * sizeof(int));
    int index = 0;
    for(int i = 0 ; i < intStrs_len; i++){
        char* int_copy = (char*)malloc((intStrs[i]) + 1);
        strcpy(int_copy,intStrs[i]);
        char* int_cut = (char*)malloc(l);
        for(int j = 0; j < l; j++){
            int_cut[j] = int_copy[s+j];
        }
        int_cut[l] = '\0'; // 아직 정수가 아니라 문자열이기 때문에 수행
        int num = atoi(int_cut); // 문자열을 정수로 변환
        if(num > k){
            answer[index++] = num;
        }
    }
    return answer;
}