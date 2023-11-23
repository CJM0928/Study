#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// == 를 사용하고, !=는 사용 지양하기

int abs(int e) {
    if (e < 0) {
        return -e;
    } return e;
}
int solution(int a, int b, int c, int d) {
    if(a == b){
        if(b == c){
            if(c == d){
                return 1111 * a; // 네주사위 나온숫자 모두 동일
            }return (10 * a + d) * (10 * a + d); // 세 주사위 나온숫자 동일
        }else if(b == d){
            return (10 * a + c) * (10 * a + c); // 세 주사위 나온숫자 동일
        }else if(c == d){
            return (a + c) * abs(a - c); //주사위가 두개씩 같은값
        }return c * d; //두 주사위가 나온값은 같지만 나머지 두개는 각각 다름
    }else if(b == c){
        if(b == d){
            return (10 * b + a) * (10 * b + a); // 세 주사위 나온숫자 동일
        }
        else if(a == d){
            return (a + b) * abs(a - b); //주사위가 두개씩 같은값
        }return a * d; //두 주사위가 나온값은 같지만 나머지 두개는 각각 다름
    }else if(c == d){
        if(a == c){
            return (10 * a + b) * (10 * a + b); // 세 주사위 나온숫자 동일
        }return a * b; //두 주사위가 나온값은 같지만 나머지 두개는 각각 다름
    }else if(a == c){
        if(b == d){
            return (a + b) * abs(a - b); //주사위가 두개씩 같은값
        }return b * d; //두 주사위가 나온값은 같지만 나머지 두개는 각각 다름
    }else if(a == d){
        return c * b; //두 주사위가 나온값은 같지만 나머지 두개는 각각 다름
    }else if(b == d){
        return a * c; //두 주사위가 나온값은 같지만 나머지 두개는 각각 다름
    }
    int min = 9999;
    if(a < min){
        min = a;
    }
    if(b < min){
        min = b;
    }
    if(c < min){
        min = c;
    }
    if(d < min){
        min = d;
    }
    return min;
}