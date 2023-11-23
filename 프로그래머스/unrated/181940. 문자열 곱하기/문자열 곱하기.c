#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// my_string을 k번만큼 반복해서 출력한다

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    const int length = strlen(my_string);
    char* answer = (char*)malloc(k * length + 1);
    // 출력시 쓰레기 값이 나오지 않도록 할당한 동적 메모리를 초기화 해준다.
    memset(answer, 0, (k * length + 1));
    // 단순히 문자열을 k 번만큼 곱해주면 되니 strcat 함수를 사용
    for(int i = 1; i <= k; i ++){
        strcat(answer, my_string);
        }
    return answer;
}

int main(){
    // my_string 의 제한조건과 k의 제한조건 설정
    const int MAX_LENGTH = 100;
    char* my_string =(char*)malloc(MAX_LENGTH * sizeof(char));
    int k = 0;
    // my_string , k 값 입력
    scanf("%s %d", my_string, &k);
    // k값은 100 이하인 제한사항
    if(k < 101){
         // solution 함수 실행
        char* result = solution(my_string,k);
        // result 출력
        printf("%s",result);
    }
    else{
        printf("k 값이 100을 초과했습니다. 프로그램을 종료합니다.");
    }
       
    return 0;
}