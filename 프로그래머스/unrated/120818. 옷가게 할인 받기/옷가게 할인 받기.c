#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// 이 문제에서 고려해야할것은 부동소수점연산이다.
// round 함수를 사용하여 반올림하면 되고, <math.h>를 추가해야한다.

int aaa (int price){
    if(price >= 100000 && price < 300000){
        return (int)round(price * 0.05);
    }else if(price >= 300000 && price < 500000){
        return (int)round(price * 0.1);
    }else if(500000 <= price){
        return (int)round(price * 0.2);
    }
    return 0;
}

int solution(int price) {
    int answer = 0;
    answer = price - aaa(price);
    return answer;
}