#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// i 라는 인덱스를 기준삼아서
// 정수 j 생성하고 pat을 돌려보는 방식이며 pat의 문자열이 등장하는 횟수는 s로 1씩 늘려준다.
// i를 myString 길이까지 for문을 돌리는것으로 만든다.
int solution(const char* myString, const char* pat) {
    int l = strlen(myString);
    int p_l = strlen(pat);
    int s = 0;
    int answer = 0;
    for(int i = 0; i<l; i++){
        int j = i;
        int k = 0;
        while(myString[j] == pat[k]){
            j++;
            k++;
            if(k == p_l){
                s++;
            }
        }
    }
    answer = s;
    return answer;
}