#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// n의 배수면 1을 리턴
// if문의 num % n 을 활용해보자 
int solution(int num, int n) {
    int answer = 0;
    if(num%n == 0) // 0이면 n의배수, 0이 아니면 n의배수가 아님을 의미하는 if문
    {
        answer = 1;
    }else
    {
        answer = 0;
    }
    return answer;
}
int main(){
    int num;
    int n;
    scanf("%d %d",num,n);
    int result = solution(num,n);
    printf("%d",result);
    
    
    return 0;
}