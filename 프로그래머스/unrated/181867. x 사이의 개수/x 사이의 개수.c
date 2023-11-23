#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// strtok 쓰지말고
// 문자열이 "x" 일때 count = 0; 으로 초기화하고
// 나머지는 count++ 해준다.
int* solution(const char* myString) {
    int l = strlen(myString);
    int count = 0;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((l+1)*sizeof(int));
    for(int i=0; i<l; i++){
        if(myString[i] == 'x'){
            answer[idx++] = count;
            count = 0;
        }else{
            count++;
        }
    }
    if(count != 0){
        answer[idx++] = count;
    }
    return answer;
}