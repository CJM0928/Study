#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// keyinput_len은 배열 keyinput의 길이입니다.
// board_len은 배열 board의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* keyinput[], size_t keyinput_len, int board[], size_t board_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    // answer에 모든 인덱스에 0입력 
    int* answer=(int*)malloc(2*sizeof(int));
    for(int i = 0; i < 2; i++){
        answer[i] = 0;
    }
    //값을 입력한다.
    for(int i = 0; i < keyinput_len; i++){
        if(strcmp(keyinput[i],"up") == 0){
            answer[1]++;
            //board의 범위를 넘어서면 board의 최대,최소값으로 수정
            if(-board[1]/2 > answer[1]){
            answer[1] = - board[1]/2;
            }else if(answer[1] > board[1]/2){
                answer[1] = board[1]/2;
            }
        }else if(strcmp(keyinput[i],"down") == 0){
            answer[1]--;
            //board의 범위를 넘어서면 board의 최대,최소값으로 수정
            if(-board[1]/2 > answer[1]){
            answer[1] = - board[1]/2;
            }else if(answer[1] > board[1]/2){
                answer[1] = board[1]/2;
            }
        }else if(strcmp(keyinput[i],"left") == 0){
            answer[0]--;
            //board의 범위를 넘어서면 board의 최대,최소값으로 수정
            if(-board[0]/2 > answer[0]){
            answer[0] = - board[0]/2;
            }else if(answer[0] > board[0]/2){
                answer[0] = board[0]/2;
            }
        }else if(strcmp(keyinput[i],"right") == 0){
            answer[0]++;
            //board의 범위를 넘어서면 board의 최대,최소값으로 수정
            if(-board[0]/2 > answer[0]){
            answer[0] = - board[0]/2;
            }else if(answer[0] > board[0]/2){
                answer[0] = board[0]/2;
            }
        }
    }
    return answer;
}