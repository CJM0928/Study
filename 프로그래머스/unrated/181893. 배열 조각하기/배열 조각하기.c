#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// query_len은 배열 query의 길이입니다.
// 입출력 예를 기준으로
// 쿼리값 4는 짝수인덱스 -> 0,1,2,3,4,5 에서 4번인덱스의 뒷부분인 5를 자른다.
// 쿼리값 1은 홀수인덱스 -> 0,1,2,3,4 에서 1번인덱스의 앞부분인 0을 자른다.
// 쿼리값 2는 짝수인덱스 -> 1,2,3,4 에서 2번 인덱스의 뒷부분인 4를 자른다. 
// arr_len을 +- 1 해주는식으로 자르는 방법이 있다.
int* solution(int arr[], size_t arr_len, int query[], size_t query_len) {
    int l = arr_len;
    int start = 0;
    int idx = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((l) * sizeof(int));
    for (int i = 0; i < query_len; i++) {
        if (i % 2 == 0) {
            l = l - (l - query[i] - 1); // 짝수 인덱스는 뒷부분 배열을 자른다.
        }
        else if (i % 2 == 1) {
            l = l - query[i];
            start = start + query[i];
        }
    }
    // l값이 변경됨에 따라 새로 answer 메모리 할당
    // answer = (int*)malloc((l+1)*sizeof(int));
    for (int i = 0; i < l; i++) {
        answer[idx++] = arr[start++];
    }
    return answer;
}