#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//테스트 15 〉	실패 (signal: aborted (core dumped))
//테스트 17 〉	실패 (signal: aborted (core dumped))
// 아마 두개의 오류는 m에서 rn으로 변경하면서 생기는 할당때문이 아닐까 추정
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* rny_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int l = strlen(rny_string);
    char* str1 = (char*)malloc((201)*sizeof(char));
    strcpy(str1,rny_string);
    // 문자를 찾는거면 strchr을 쓰자, 문자열을 찾는거라면 strstr을 찾는게 좋지만.
    char* ptr = strchr(str1,'m');
    while(ptr != NULL){
        // memmove를 통해 ptr의 포인터 주소를 옮기고, strlen또한 뒤에 +1 추가해서
        // m을 rn으로 바꾸기 위한 작업을 수행한다.
        memmove(ptr + 2, ptr + 1, strlen(ptr + 1) + 1);
        // 여기서 strncpy의 ptr은 memmove에서 이동한 (ptr + 2)의 ptr이다. 
        strncpy(ptr, "rn", 2);
        ptr = strchr(ptr + 2, 'm');
    }
    return str1;
}