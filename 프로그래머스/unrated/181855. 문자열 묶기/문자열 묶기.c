#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// strArr_len은 배열 strArr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// 이차원배열이니까 배열의 각 문자열의 길이를 측정, 그 측정값을 봐서 가장많은 값을 출력
int solution(const char* strArr[], size_t strArr_len) {
    int answer = 0;
    int max = 0;
    int* index = (int*)malloc((30+1)*sizeof(int));
    int n = 0;
    // index에 각 값들을 0을 넣어주기
    // strArr의 원소의 길이는 최대 30까지임.
    for(int i = 0; i < 31; i++){
        index[i] = 0;
    }
    //strArr의 길이값을 index[n]에 +1 더해주기
    for(int i = 0; i<strArr_len; i++){
        n = strlen(strArr[i]);
        index[n]++;
    }
    //여기서 index[n]의 값들중 제일 큰값을 max의 넣어주기
    for(int i = 0; i < 31; i++){
        if(max <= index[i]){
            max = index[i];
        }
    }
    // strArr 문자열 배열에서 0~30까지의 길이중에서 가장 많이 가진 max값을 출력한다. 
    answer = max;
    return answer;
}