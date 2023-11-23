#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// num_list_len은 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int m = 1;   // 모든 원소의 곱 기본값 0으로 입력하면 절대안됨!!!
    int n = 0; // 모든 원소의 합의 제곱
    for (int i = 0; i < num_list_len; i++) {
        m *= num_list[i];
        n += num_list[i];
    }
    n *= n;
    return (m < n) ? 1 : 0;
}
// int main(){
//     int a[];
//     int b;
//     scanf("%s %d", a[],&b);
//     if(a <= 9 && b <= 10){
//         int result = solution(a,b);
//         printf("%d",result);
//     }
//     return 0;
// }