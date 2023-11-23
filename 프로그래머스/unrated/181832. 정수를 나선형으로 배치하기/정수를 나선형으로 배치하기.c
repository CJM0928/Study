#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//배열 n*n 크기만큼 선언.
//while 문으로 answer의 빈칸이 모두 채워질 때까지 반복. => n*n을 의미
//temp 변수를 활용하여 각 축에 변화를 저장.

//right down left up 순으로 반복,
//right 후 down하기위해 y를 +1, down 후 x를 -1, left 후 y를 -1, up 후, x를 +1한다.
int** solution(int n) {
    int x = 0; // 열
    int y = 0; // 행
    int temp = 0; // 임시로 보관
    int idx = 1;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int** answer = (int**)malloc(((n*n)+1)*sizeof(int*));
    for(int i = 0; i < n; i++){
        answer[i] = (int*)malloc((n+1)*sizeof(int));
    }
    while(n*n >= idx){
        //right를 먼저 수행.
        for(int right = x; right < n - x; right++){
            answer[y][right] = idx++;
            temp = right;
            if(idx == n*n){
                break;
            }
        }
        x = temp;
        y++;
        for(int down = y; down <= n - y; down++){
            answer[down][x] = idx++;
            temp = down;
            if(idx == n*n){
                break;
            }
        }
        y = temp;
        x--;
        for(int left = x; left >= n - y -1; left--){
            answer[y][left] = idx++;
            temp = left;
            if(idx == n*n){
                break;
            }
        }
        x = temp;
        y--;
        for(int up = y; up > x; up--){
            answer[up][x] = idx++;
            temp = up;
            if(idx == n*n){
                break;
            }
        }
        y = temp;
        x++;
    }
    return answer;
}