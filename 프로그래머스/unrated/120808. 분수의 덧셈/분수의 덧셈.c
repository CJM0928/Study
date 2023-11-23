#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//유클리드 호제법과 같은 최대 공약수를 효율적으로 찾는 알고리즘을 사용 권장
//재귀함수를 활용한다.
// a를 b로 나눠서 b가 0이 될때의 a를 구한다. (분모의 약수를 구한다)
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a % b);
}
int* solution(int numer1, int denom1, int numer2, int denom2) {
    int temp = 1;
    int temp2 = 1;
    int* answer = (int*)malloc(2*sizeof(int));
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    answer[0] = (numer1 * denom2) + (numer2 * denom1);
    answer[1] = denom1 * denom2;
    // for(int i = 1; i < 1000; i++){
    //     if(answer[0] % i == 0 && answer[1] % i == 0){
    //         temp2 = i;   
    //     }
    // }
    // if(temp2 > 0){
    //     answer[0] = answer[0] / temp2;
    //     answer[1] = answer[1] / temp2;
    // }
    temp = gcd(answer[0],answer[1]);
    answer[0] /= temp;
    answer[1] /= temp;
    
    return answer;
}