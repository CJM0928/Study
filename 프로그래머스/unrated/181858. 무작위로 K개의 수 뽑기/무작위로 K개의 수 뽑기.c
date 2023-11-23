#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int k) {
    int l = arr_len;
    int idx = 0;
    int index = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((100001) * sizeof(int));
    // 우선 answer의 인덱스에 전부 -1로 채우기
    for (int i = 0; i < k; i++) {
        answer[i] = -1;
    }

    for (int i = 0; i < l; i++){
        idx = 0;
        for (int j = 0; j < k; j++) {
            if (arr[i] == answer[j]) {
                idx = 1;
                break;
            }
        }
        if (!idx) {
            answer[index++] = arr[i];
        }
    }

    return answer;
}