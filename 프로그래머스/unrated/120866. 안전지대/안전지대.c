#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// board_rows는 2차원 배열 board의 행 길이, board_cols는 2차원 배열 board의 열 길이입니다.
// [x][y] == 1이면
// [x-1][y-1,y,y+1] 3개 [x][y-1,y,y+1] 2개 [x+1][y-1,y,y+1] 3개는 answer++ 하지않음.
// x == 0이면 x-1은 제외하고 y == 0이면 y-1은 제외 x == 0 y == 0이면 x-1,y-1은 제외
// x == 4면 x+1은 제외 y == 4면 y +1은 제외 x == 4 y == 4면 x+1 y+1은 제외
// 이렇게 주변은 2로 변경하되, 만약 변경하려는 위치가 1이 존재한다면 그친구는 제외한다.
// 그리고 폭탄주변이 0이아닌 2로 되어있다면 해당부분은 continue로 넘어간다.
int solution(int** board, size_t board_rows, size_t board_cols) {
    int answer = 0;
    for(int i = 0; i < board_rows; i++){
        for(int j = 0; j <board_cols; j++){
            if(board[i][j] == 1 ){
                for(int k = i-1; k <= i+1; k++){
                    for(int l =j-1; l <= j+1; l++){
                        if(k>=0 && l>=0 && k<board_rows && l < board_cols){
                            if(board[k][l] == 1 &&( i != k || j != l)){
                                continue;    
                            }else{
                                board[k][l] = 2; // 안전지대가 아니라는 의미로 남김
                            }
                        }
                    }
                }    
            }
        }
    }
    for(int i = 0; i < board_rows; i++){
        for(int j = 0; j < board_cols; j++){
            if(board[i][j] == 1 || board[i][j] == 2){
                continue;
            }else{
                answer++;
            }
        }
    }
    return answer;
}