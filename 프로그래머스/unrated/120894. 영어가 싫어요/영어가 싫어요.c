#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
long long solution(const char* numbers) {
    long long answer = 0;
    int n = 0;
    for(int i = 0; i <strlen(numbers); i++){
        if(numbers[i] == 'o'){
            n = 1;
            i = i+2;
            answer = answer*10 + n;
        }else if(numbers[i] == 'z'){
            n = 0;
            i = i+3;
            answer = answer*10 + n;
        }else if(numbers[i] == 'e'){
            n = 8;
            i = i+4;
            answer = answer*10 + n;
        }else if(numbers[i] == 'n'){
            n = 9;
            i = i+3;
            answer = answer*10 + n;
        }
        if(numbers[i] == 't'){
            if(numbers[i+1] == 'w'){
                n = 2;
                i = i+2;
                answer = answer*10 + n;
            }else if(numbers[i+1] == 'h'){
                n = 3;
                i = i+4;
                answer = answer*10 + n;
            }
        }
        if(numbers[i] == 'f'){
            if(numbers[i+1] == 'o'){
                n = 4;
                i = i +3;
                answer = answer*10 + n;
            }else if(numbers[i+1] == 'i'){
                n = 5;
                i = i+3;
                answer = answer*10 + n;
            }
        }
        if(numbers[i] == 's'){
            if(numbers[i+1] == 'i'){
                n = 6;
                i = i+2;
                answer = answer*10 + n;
            }else if(numbers[i+1] == 'e'){
                n = 7;
                i = i+4;
                answer = answer*10 + n;
            }
        }
    }
    return answer;
}