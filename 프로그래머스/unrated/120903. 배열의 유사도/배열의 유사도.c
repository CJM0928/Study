#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// s1_len은 배열 s1의 길이입니다.
// s2_len은 배열 s2의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// strcmp를 사용해서 문자열 배열의 원소를 비교해서 같으면 0을 이용하여 같은 원소개수 출력.
int solution(const char* s1[], size_t s1_len, const char* s2[], size_t s2_len) {
    int s = 0;
    for(int i = 0; i < s1_len; i++){
        for(int j = 0; j < s2_len; j++){
            int k = 0; // 배열의 주소 k 
            while(*(s1[i]+k) == *(s2[j]+k)){ //s1과 s2의 원소값이 같을때 반복문 진입
                if(*(s1[i]+k) == '\0' && *(s2[j]+k) == '\0'){ // s1과 s2의 원소같이 같으면서 
                                                             // NULL위치또한 같으면 s값증가.
                s++;
                break;
                }
                k++; // if문 끝나면 while 하기위해서 i , j 의 주소값 k 1씩증가.
            }
        }
    }
    return s;
}