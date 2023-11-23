#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// 10을 / 해서 나온값을 10 + 한다.
// 그리고 10을 / 해서 나온 1을 +한다 11

// 1081 /해서 108이 나오고 + 한다 1081을 % 10해서 1을 따로 +한다
// 108 /해서 10이 나오고 + 한다 108을 % 10해서 8을 따로 +한다
// 10을 / 해서 1이 나오고 + 한다. 추가로 +1 해서 나머지 10도 하나로 합친다.

int solution(int chicken) {
    int answer = -1;
    int coupon = 0;
    int eat = 0;
        
    eat = eat + (chicken / 10);
    coupon = coupon + (chicken / 10) + (chicken % 10);
        
    while(coupon >= 10){
        eat = eat + (coupon / 10);
        coupon = ( coupon / 10 ) + (coupon % 10);
        if(coupon < 10){
            break;
        }
    }
    answer = eat;
    return answer;
}