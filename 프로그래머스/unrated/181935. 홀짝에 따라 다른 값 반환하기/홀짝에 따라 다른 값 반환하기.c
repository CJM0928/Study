#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// n이 홀수일때는 n % 2 != 0 조건 // n 이 짝수일때는 n % 2 == 0 조건을 이용
// 홀수일때 for문 짝수일때 for문 활용하면 좋을듯

// n이 홀수일때 함수
int solution_O(int n) {
    int answer = 0;
    // n이 7일때
    for(int i = 1; i <= n; i++){
        if(i % 2 != 0){
            answer+=i; // answer에 1+3+5+7+....+ 순으로 입력됨
        }
    }
    return answer;
}

int solution(int n) {
    int answer = 0;
    // n이 10일때 //pow(i,2); == 수학에서 i^2와 같은 의미
    if(n % 2 == 0){
        for(int i = 1; i <= n; i++){
            if(i % 2 == 0){
                answer+=pow(i,2); //for문 2^2 + 4^2 + 6^2 + .... + 순으로 answer에 더해줌
            }   
        }         
    }else if(n % 2 != 0){
        answer = solution_O(n); // n이 홀수라면 solution_O 함수로 진입
    }
    return answer;
}
int main(){
    int n = 0;
    int result = 0;
    scanf("%d",&n);
    // n이 100이하의 숫자만 받을수있는 제한사항
    if(n <= 100)
    {
        result = solution(n); // 100이하의 숫자로 받으면 솔루션 함수
    }
    else
    {
        printf("제한사항을 초과한 수를 입력받았습니다."); // 100 초과로받으면 끝
    }
    printf("%d", result);
    return 0;
}