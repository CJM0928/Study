#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int age) {
    int idx = 0;
    int temp = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(1000*sizeof(char));
    while(age > 0){
        temp = age % 10;
        if(temp == 0){
            answer[idx++] = 'a';
        }else if(temp == 1){
            answer[idx++] = 'b';
        }else if(temp == 2){
            answer[idx++] = 'c';
        }else if(temp == 3){
            answer[idx++] = 'd';
        }else if(temp == 4){
            answer[idx++] = 'e';
        }else if(temp == 5){
            answer[idx++] = 'f';
        }else if(temp == 6){
            answer[idx++] = 'g';
        }else if(temp == 7){
            answer[idx++] = 'h';
        }else if(temp == 8){
            answer[idx++] = 'i';
        }else if(temp == 9){
            answer[idx++] = 'j';
        }
        age = age / 10;
    }
    answer[idx] = '\0';
    for(int o = 0; o < idx/2; o++){
        char temp1 = answer[o];
        answer[o] = answer[idx-1-o];
        answer[idx-1-o] = temp1;
    }
    return answer;
}