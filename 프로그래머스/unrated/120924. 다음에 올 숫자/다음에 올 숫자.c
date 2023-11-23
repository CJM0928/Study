#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len은 배열 common의 길이입니다.
// 등비수열은 a1 
//           a2 / a1
//           a3 / a2 이다.
int solution(int common[], size_t common_len) {
    int answer = 0;
    int length = common_len;
    int n = 0;
    int* temp = (int*)malloc((length+1)*sizeof(int));
    for(int i = 0; i < length -1; i++){
        n = common[i+1] - common[i];
        temp[i] = n;
    }
    if(temp[0] == temp[1]){ // 등차수열
        answer = common[length-1] + n;
    }else if( (temp[0] != temp[1]) != 0 ){ // 등비수열
        answer = common[length-1] * common[1] / common[0];
    }else if(temp[0] ==temp[1] == 0){
        answer = common[length-1] + n;
    }
    return answer;
}