#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** solution(const char* picture[], size_t picture_len, int k) {
    int inputLength = strlen(picture[0]) + k; // 입력 문자열의 길이
    int outputLength = (inputLength * k) + k; // 결과 문자열의 길이

    char** answer = (char**)malloc((20 * 20 * 10) * sizeof(char*)); 
    // 결과 문자열을 저장할 배열 동적 할당

    for (int i = 0; i < picture_len * k; i++) {
        answer[i] = (char*)malloc((20 * 20 * 10) * sizeof(char)); 
        // 각 행에 대한 결과 문자열 할당
        int idx = 0;
        for (int j = 0; j < inputLength; j++) {
            for (int l = 0; l < k; l++) {
                answer[i][idx++] = picture[i/k][j]; 
                // 문자열을 k배로 늘려서 결과 문자열에 복사
                // i/k하는 이유는 입출력 예를보면 k배로 늘린 문자열을 k번 출력하기때문에
                // k가 2일때 i는 0,1일때 answer[0,1]에 picture[0]의 배열을 넣는다.
                // i가 2,3 일때 answer[2,3] 에는 picture[1]의 배열을 넣는다.
            }
        }
        answer[i][idx] = '\0'; // NULL 문자 추가
        // 문자또는 문자열의 배열은 항상 마지막값을 null 처리 해줘야 쓰레기값이 사라짐.
    }
    return answer;
}