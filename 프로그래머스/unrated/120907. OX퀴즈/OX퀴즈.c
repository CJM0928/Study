#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// quiz_len은 배열 quiz의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// "숫자 부호 숫자 = 숫자"
char** solution(const char* quiz[], size_t quiz_len) {
    int length = quiz_len;
    char** answer = (char**)malloc((length+1) * sizeof(char*));

    for (int i = 0; i < quiz_len; i++) {
        int X, Y, Z;
        char op;
        sscanf(quiz[i], "%d %c %d = %d", &X, &op, &Y, &Z);

        int result;
        if (op == '+') {
            result = X + Y;
        } else if (op == '-') {
            result = X - Y;
        }

        if (result == Z) {
            answer[i] = "O";
        } else {
            answer[i] = "X";
        }
    }

    return answer;
}