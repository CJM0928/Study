#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 임시 배열 생성
// 반복문으로 각 인덱스에 1을 저장.
// 각 인덱스 크기 비교해서
// 작을때마다 해당 인덱스의 값에 +1 해주고
// 그대로 출력.
// 정렬 이용하면 될듯. 자리
int* solution(int emergency[], size_t emergency_len) {
    int l = emergency_len;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    //int* answer = (int*)malloc((l+1)*sizeof(int));
    int* temp = (int*)malloc((l+1)*sizeof(int));
    for(int i = 0; i < l; i++){
        temp[i] = 1;
    }
    for(int i = 0;  i< l; i++){
        for(int j =0; j <l; j++){
            if(i == j){
                continue;
            }
            if(emergency[i] > emergency[j]){
                continue;
            }else if(emergency[i] < emergency[j]){
                temp[i]++;
            }
        }
    }
    return temp;
}