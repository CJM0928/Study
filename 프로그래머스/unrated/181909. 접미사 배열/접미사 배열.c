#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// strcmp,strcpy 사용 추가로 버블정렬 
// strcmp는 비교, strcpy는 복사
// 출력값의 순서 기준은 a b c d e f g 순으로
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int l = strlen(my_string);
    int cnt = 0;
    // char** answer 이므로 sizeof(char*) 으로 할당
    char** answer = (char**)malloc((l + 1) *sizeof(char*));
    // my_string[j] 의 문자들을 str의 문자열에 저장후 answer[cnt]에 보낸다.
    for(int i = 0; i < l; i++){
        int index =0;
        char* str = (char*)malloc((l + 1) * sizeof(char));
        for(int j = i; j < l; j++){
             str[index++] = my_string[j];
        }
        str[index] = '\0';
        answer[cnt++] = str;
    }
    // answer[cnt]에 보내진 문자열은 strcmp로 비교해본다.
    // strcmp(a[i],a[j]>0) 을 사용하여 양수가 된다면 사전적으로 a[i]가 더 앞으로 온다는 의미므로
    // 스왑을 시작한다.
    //result에 나온 값들은 사전적으로 비교되서 나열된 값들이다.
    for(int i = 0; i < cnt; i++){
        for(int j = i + 1; j < cnt; j++){
            if(strcmp(answer[i],answer[j])>0){
                char* temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }
    return answer;
}