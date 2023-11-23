#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int combine(int a, int b){
    int a_c = a;
    int b_c = b;
    while(b_c > 0){
        a_c*=10;
        b_c/=10;
    }
    return a_c+b;
}

int solution(int a, int b) {
    int answer;
    int a_b = combine(a,b);
    int Multiplication = 2*a*b;
    if(a_b >= Multiplication){
        answer = a_b;
    }else{
        answer = Multiplication;
    }
    return answer;
}
int main() {
    int a;
    int b;
    scanf("%d %d",a,b);
    if(a <= 10000 && b <= 10000){
        int result = solution(a,b);
        printf("%d",result);
    }else{
        pirntf("제한사항을 초과한 수를 입력받았습니다.");
    }
    return 0;
}