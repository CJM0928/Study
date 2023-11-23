#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 공배수 : 두 개 이상의 자연수의 "공통인 배수"를 말한다
int solution(int number, int n, int m) {
    int answer = 0;
    if(number % n == 0)  // number 가 n의 배수라면 m의 배수인지 확인하러 내려감
    {
        if(number % m ==0) // 마지막으로 number 가 m의 배수인지 확인하는 if문 
        {
            answer = 1; // n , m 둘다 배수가 되는 공배수이므로 answer는 1
        }
        else
        {
            answer = 0; // n의 배수지만 m의 배수가 아니면 answer는 0
        }
    }
    else
    {
        answer = 0; // n의 배수가 아니라서 answer는 0
    }
    return answer;
}
int main(){
    int number;
    int n;
    int m;
    scanf("%d %d %d",number,n,m);
    int result = solution(number,n,m);
    printf("%d",result);
    return 0;
}