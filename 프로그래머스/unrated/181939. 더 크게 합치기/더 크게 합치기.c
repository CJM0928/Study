#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a ⊕ b 그리고 b ⊕ a 를 수행해본다.
// a는 10씩 곱해주고, b는 10씩 나누기로 맞춰준다.
int combine (int a, int b){
    int a_c = a;
    int b_c = b;
    while(b_c > 0){
    a_c*=10;      // a = 8 80 800 8000 // 100 1000
    b_c/=10;      // b = 100 10 1 0    //   8    0
    }
    return a_c+b ; // 8100             // 1008
}

int solution(int a, int b) {
    int answer = 0;
    int a_b = combine (a,b); // a와b의 숫자를 합침
    int b_a = combine (b,a); // b와a의 숫자를 합침
    if(a_b >= b_a)           // 합친 a_b와 b_a의 크기를 비교해서 큰 수를 출력
    {
        answer = a_b;
    }else
    {
        answer = b_a;
    }
    return answer;
}
int main() {
    int a; 
    int b;
    scanf("%d %d", a, b); // a ,b 입력
    
    // 제한사항 a,b 가 10000을 초과할 경우 끝내기
    if( a <= 10000 && b <= 10000 ){
        int result = solution(a,b); // 솔루션 진입
        printf("%d\n",result);      // 결과값 출력
    }
    else{
        printf("제한사항을 초과한 정수를 입력받았습니다."); // 끝내기
    }
    return 0;
}