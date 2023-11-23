#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// spell_len은 배열 spell의 길이입니다.
// dic_len은 배열 dic의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// 1.word를 만들고 memset을통해 각 자리마다 0을 입력후 spell의 원소들을 strcat을통해 입력한다.
// 2.strcmp를통해 word 와 dic를 비교해서 같으면 true를 한다.
// 3.spell의 문자를 swap하여 변경하고 다시 재귀로 호출한다.
// 4.1~2과정을 반복후 내려와서 원래값으로 복구한다.
// 5.복구한값을 토대로 다시 for문을 수행하여 spell의 문자를 바꾼다.
// 6.바꾼문자를 다시 word에 새롭게 덮는다.
// 7.덮은문자를 strcmp하고 끝나면 다시 원래값으로 복구한다.
// 8. 줄여서 말하면 swap -> strcat -> strcmp -> 복구 순으로 for문이 끝날때까지 반복.
void permute(char* spell[], int start, int end, const char* dic[], size_t dic_len, bool* found){
    char word[11]; // 단어 최대 길이 (문제 제한에 따라 조절 가능)
    memset(word, 0, sizeof(word));
    
    for(int i = 0; i <= end; i++){
        strcat(word,spell[i]);
    }
    for(int i =0; i < dic_len; i++){
        if(strcmp(word,dic[i]) == 0){
            *found = true;
            return;
        }
    }
    for(int i = start; i <= end; i++){
        char* temp = spell[start];
        spell[start] = spell[i];
        spell[i] = temp;
    
        permute(spell,start+1,end,dic,dic_len,found);

        // 복구하는데 기준은 for문의 i와 start값기준
        temp = spell[start];
        spell[start] = spell[i];
        spell[i] = temp;
    }
}
int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
    bool found = false;
    permute(spell,0,spell_len-1,dic,dic_len,&found);
    if(found){
        return 1;
    }
    return 2;
}