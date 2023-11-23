#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 입출력을 예시로 조건문을 짜서 삼항연산자로 1 또는 0을 출력하는게 좋아보인다.
//삼항 연산자 (조건)? 참 : 거짓 형태 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char *ineq, const char *eq, int n, int m) {
    // *ineq와 *eq를 사용하는 이유는 해당 문자열의 첫 번째 문자를 비교하기 위해서
    // ineq와 eq를 사용해버린다면 문자열그 자체로 비교해버리기 때문에 포인터와 정수 간의 비교 오류 
    if(*ineq == '<' && *eq == '='){
        return (n<=m)?1:0;
    }else if(*ineq == '>' && *eq == '!'){
        return (n>m)?1:0;
    }else if(*ineq == '<' && *eq == '!'){
        return (n<m)?1:0;
    }else if(*ineq == '>'&& *eq == '='){
        return (n>=m)?1:0;
    }
}