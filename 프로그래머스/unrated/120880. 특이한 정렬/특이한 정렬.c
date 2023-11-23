#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// numlist_len은 배열 numlist의 길이입니다.
// n을 numlist랑 +-해서 가까운값(차이가 적은값)을 우선 출력한다. 이런문제같음
// for문 굴려서 차이값을 만들고 그 차이값을 우선 i가 0일때는
// 임시 인덱스만들어서 모든값에 1을 넣어주고,
int* solution(int numlist[], size_t numlist_len, int n) {
    int length = numlist_len;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((length+1)*sizeof(int));
    int* index = (int*)malloc((length+1)*sizeof(int));
    int idx = 0;
    //answer에 n값과 차이(절대값)을 넣고, index는 해당하는 인덱스를 넣어 정리
    for(int i = 0; i < length; i++){
        answer[i] = abs(n-numlist[i]); // 예시1기준 3 2 1 0 1 2
        index[i] = i;                 //          0 1 2 3 4 5
    }
    for(int i = 0; i < length-1; i++){
        for(int j = i+1; j < length; j++){
            // 일반적으로 i j 비교해서 큰값을 뒤로 넘기지만, 에외가 있을경우 '한번만' 넘긴다
            // || 뒤에 answer[i] > answer[j] 등등을 추가한다면 배열이 꼬여버린다는점을 유의
            if(answer[i] > answer[j] || (answer[i] == answer[j] && numlist[index[i]] < numlist[index[j]] )){
                
                int temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
                
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }   
        }
    }
    for(int i = 0; i < length; i++){
        answer[idx++] = numlist[index[i]];
    }
    return answer;
}