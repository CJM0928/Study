#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요
// binomial은 이항분포 라는 뜻
// 이상하게 생각할거없이
// 문제는 a,op,b를 주고 임의값을 scanf하여 + - * 연산 하라는 의미
int solution(const char* binomial) {
    int a,b;
    char op;
    // sscanf를 사용하여 binomial이라는 문자열에 값을 가져와 순서대로 읽어온다.(a,op,b에)
    // 반드시 a op b 에 주소인 &a &op &b를 사용할것
    sscanf(binomial, "%d %c %d", &a, &op, &b);

    // 이항식 계산
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
    }
}