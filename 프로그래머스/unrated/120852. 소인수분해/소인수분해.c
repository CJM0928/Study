#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//더이상 나눠지지않는 약수 => 소인수분해
// i값으로 나눠질수있을때 n값을 i로 나누고나서 
// 다시 반복문을 진행하는식으로 n값을 작게 만들어준다.
int* isprime(int n){
    for(int i =2; i < n; i++){ // i가 2일때는 return 1을 해줄수있게 짜야함.
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((n+1)*sizeof(int));
    int idx = 0;
        for(int i = 2; i <= n; i++){
            if(isprime(i) && n % i == 0 ){
                answer[idx++] = i;
                n /= i;
            }
        }
    return answer;
}