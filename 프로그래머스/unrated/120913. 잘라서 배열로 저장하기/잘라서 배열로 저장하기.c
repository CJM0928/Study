#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// 예시 1과같이 마지막 인덱스의 슬라이스에 2개가 비는데 이걸 자세히 할당해줘야한다.
char** solution(const char* my_str, int n) {
    int l = strlen(my_str);
    int idx = 0;
    int length = (l % n == 0) ? (l / n) : (l / n +1); // 나머지0이 아니면 +1해준다.
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc((l+1)*sizeof(char*));
    for(int i = 0; i < length; i++){
        int slice_length = (i == length - 1) ? (l - i*n):n; // i인덱스의 slice 길이 정하는코드
        answer[i] =(char*)malloc((slice_length + 1)*sizeof(char));
        for(int j = 0; j < n; j++){
            answer[i][j] = my_str[idx++];
            if(my_str[idx] == '\0'){
                break;
            }
        }
        answer[i][slice_length] = '\0'; // i인덱스의 마지막slice는 항상 null로 초기화
    }
    return answer;
}