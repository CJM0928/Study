#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// int solution_2(int a, int b, int c){
//     for(int i = 0; i < 3; i++){
//         a = a * a;
//         b = b * b;
//         c = c * c;
//     }
//     return a+b+c;
// }
// int solution_1(int a, int b, int c){
//     for(int i = 0; i < 2; i++){
//         a = a * a;
//         b = b * b;
//         c = c * c;
//     }
//     return a+b+c;
// }
int solution(int a, int b, int c) {
    int answer = 0; 
    if(a == b && b == c && c == a){
        answer = ((a + b + c) * ( a*a + b*b + c*c ) * ( a*a*a + b*b*b + c*c*c ));
    }else if(a != b && b != c && a != c){
        answer = (a + b + c);
    }else{
        answer =((a + b + c) * ( a*a + b*b + c*c ));
    }
    return answer;
}
int main(){
    int a;
    int b;
    int c;
    scanf("%d %d %d",a,b,c);
    if(a <= 6 && b <= 6 && c <= 6){
        int result = solution(a,b,c);
        printf("%d",result);
    }else{
        printf("제한사항을 초과한 값을 입력받았습니다.");
    }
    return 0;
}