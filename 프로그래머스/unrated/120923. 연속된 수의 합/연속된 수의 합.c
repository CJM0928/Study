#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 예 1기준으로
// 시작을 0부터한다.
// 합친값이 total 보다 작으면 1부터 시작
// 만약 합친값이 total보다 크면 -1부터 시작 하는 식으로 다만 -1이면 0 1 2 3 이런식으로 앞으로 나아간다. total은 0부터시작하기때문
int* solution(int num, int total) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((num)*sizeof(int));
    int number = 0;
    int start = 0;
    int result = -1;
    while(result != total){
        number = start;
        result = 0;
        for(int i = 0; i < num; i++){
            answer[i] = number;
            result += number;
            number++;
        }
        
        if(result > total){
            start--;
        }else if (result < total){
            start++;
        }else if(result == total){
            break;
        }
    }
    return answer;
}