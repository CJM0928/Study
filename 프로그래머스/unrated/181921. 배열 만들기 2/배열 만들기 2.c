#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1. 5배의수 and 10의배수 찾는다.
// 2. 그중에서 계속 10으로 나누기해서 5만 남는 친구들을 찾는다.
int* solution(int l, int r) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * (r - l));
    int index = 0;
    bool answer_i = false;
    for(int i = l; i <= r; i++){
        int num = i;
        while(num){
            if(num % 10 == 0 || num % 10 == 5){
                num /= 10; // 얘가 m / 10; 을 해버려서 해결이 안된거였음
                answer_i = true;
            }else{
                answer_i = false;
                break;
            }
        }if(answer_i){
            answer[index++] = i;
        }else if(index == 0){
            answer[index] = -1;
        }
    }
    // if(index == 0){
    //     answer[index++] = -1;
    // }
    return answer;
}