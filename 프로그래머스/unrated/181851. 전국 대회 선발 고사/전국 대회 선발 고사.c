#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// rank_len은 배열 rank의 길이입니다.
// attendance_len은 배열 attendance의 길이입니다.
int solution(int rank[], size_t rank_len, bool attendance[], size_t attendance_len) {
    int l = rank_len;
    int idx = 0;
    int answer = 0;
    int max = 0;
    int index = 0;
    int* rank1 =(int*)malloc((l+1)*sizeof(int));
    int* rank2 =(int*)malloc((l+1)*sizeof(int));
    int* rank3 =(int*)malloc((l+1)*sizeof(int));  // 수정: rank3의 크기를 l+1로 변경
    for(int i = 0; i < l; i++){
        if(attendance[i] == false){
            continue;
        }else if(attendance[i] == true){
            rank1[idx] = rank[i];
            rank2[idx] = i;
            idx++;
        }
    }
    //rank1[] = {7,2,5,4} // rank 1,2,3,4 인덱스값
    //rank2[] = {1,2,3,4} // rank 인덱스 1,2,3,4
    if(idx != 2){
        for(int j = 0; j < idx; j++){
            for(int k = j+1; k<idx; k++){
                if(rank[rank2[j]] > rank[rank2[k]]){
                    rank3[index] = rank2[k];
                    rank2[k] = rank2[j];
                    rank2[j] = rank3[index];
                    index++;
                }       
            }
        }
    }
    answer = (rank2[0]*10000) + (rank2[1]*100) + rank2[2];
    return answer;
}