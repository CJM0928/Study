#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 이 문제의 의도는 순서를 무작위로 막 바꿀수있게 하는 것.
// 그래서 이 문제는 before와 after의 각 문자가 같다면 바꿀수있다는 의미로 1을 출력
// 1차적으로 before와 after의 문자 길이를 비교한다.
// 그다음 before의 문자들을 after의 문자와 비교한다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* before, const char* after) {
    int l = strlen(before);
    int ll = strlen(after);
    int string[26] = {0}; // 여기서 26의 의미는 a~z까지 개수
    
    if(l != ll){
        return 0;
    }
    // string의 각 인덱스를 +1해준다 (a~z까지의 인덱스를 정수화했음)
    for(int i = 0; i < l; i++){
        string[before[i] - 'a']++;
        string[after[i] - 'a']--;
    }
    // 같은 문자열이 없어서 -1이 된다면 0을 반환
    for(int i = 0; i < 26; i++){
        if(string[i] != 0){
            return 0;
        }
    }
    return 1;
}