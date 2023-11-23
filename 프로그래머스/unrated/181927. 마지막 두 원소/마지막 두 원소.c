#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int length = num_list_len;
    int* answer = (int*)malloc((length * sizeof(int)) + 1 );
    for(int i = 0; i < length; i++){
        answer[i] = num_list[i];
    }
    if(num_list[length - 1] > num_list[length - 2]){
        answer[length] = (num_list[length-1] - num_list[length-2]);
    }else if(num_list[length - 2] >= num_list[length - 1]) // 크지 않기때문에 ' >= ' 사용
    {
        answer[length] = (num_list[length-1] * 2);
    }
    return answer;
}
int main() {
    int a = 0;
    size_t b = 0;
    printf("값을 입력해주세요 : ");
    scanf("%d %zu", &a, &b);

    if (2 <= b && b <= 10) {
        int num_list[] = {1, 2, 3, 4, 5};  // 예시 배열
        size_t num_list_len = sizeof(num_list) / sizeof(num_list[0]);
        int* result = solution(num_list, num_list_len);

        for (size_t i = 0; i <= num_list_len; i++) {
            printf("%d ", result[i]);
        }

        free(result);  // 메모리 해제
    }

    return 0;
}