#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 팩토리얼을 구현해서 풀어보았지만 너무 큰수로인해 불가능에 가까우니
// 동적계획법을 사용해본다
// 그림은 피라미드 생각하면된다.

int solution(int balls, int share) {
    if(share == 0 || balls == share){
        return 1;
    }
    int dp[31][31] = {0};
    for(int i = 1; i<=balls; i++){
        dp[i][0] = dp[i][i] =1; // 양쪽끝
        for(int j = 1; j < i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; // 양쪽끝에 사이의 값들을 계산.
        }
    }
    return dp[balls][share];
}