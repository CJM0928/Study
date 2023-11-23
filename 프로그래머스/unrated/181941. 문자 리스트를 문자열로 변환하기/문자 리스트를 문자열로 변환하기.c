#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// C언어에서는 문자열이 없기때문에 char 변수들의 배열 혹은 포인터 형태로 선언해야한다
// 이 문제에서는 포인터 형태로 해결한다.
// signal: segmentation fault (core dumped) : NULL인 메모리에 접근할 때 발생한다.
// (잘못된 메모리 참조)

// arr[]은 배열 형태의 문자열 (포인터 형태의 문자열과 다르게 주어진만큼 할당크기 정해지는게 디폴트)
// arr_len은 배열 arr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용
// const char* arr[] : arr[] 열 역참조 하지 못하게 const 한 것

char* solution(const char* arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경
    char* answer = (char*)malloc((arr_len + 1) * sizeof(char));
    // answer배열에 arr 배열값 입력 
    for (int i = 0; i < arr_len; i++) {
        answer[i] = *arr[i];
    }
    // answer 배열에 마지막 NULL 입력 (그래야 출력이 정확히되서 오류안나옴 )
    answer[arr_len] = '\0';
    // answer 배열 그대로 반환
    return answer;
}

int main() {
    // 제한사항 : 길이 1이상 200이하
    // 포인터 형태의 문자열 arr 기본 크기는 8byte
    const int MAX_LENGTH = 200;
    char* arr = (char*)malloc(MAX_LENGTH + sizeof(char));
    // arr에 값을 입력
    // arr은 arr[0] 와 같은 의미로 &arr은 필요없음
    scanf("%s", arr);
    // solution 함수 호출
    char* result = solution(*arr, MAX_LENGTH);
    //=malloc를 사용했으면 메모리 누수 방지위해서 써주는게 좋음!!
    free(arr);
    free(result);
    // 결과 호출
    printf("%s", result);
}