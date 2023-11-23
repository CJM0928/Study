#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, bool flag) {
    int answer = 0;
    if(flag == true){
        answer = a + b;
    }else{
        answer = a - b;
    }
    return answer;
}
int main(){
    int a;
    int b;
    bool flag;
    scanf("%d %d %d",a,b,flag);
    if(a <= 1000 && b <= 1000){
        int result = solution(a,b,flag);
        printf("%d",result);
    }
}