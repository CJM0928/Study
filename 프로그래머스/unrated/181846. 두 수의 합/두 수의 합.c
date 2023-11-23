#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* a, const char* b) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len1=strlen(a)-1,len2=strlen(b)-1;
    char *answer=(char*)malloc(sizeof(char)*100001);
    answer[100001]=0;
    memset(answer,'0',sizeof(char)*100000);
    int s_idx=100001;
    int carry=0;

    while(len1 >= 0 || len2 >= 0 || carry)
    {
        int sum = carry;
        if(len1 >= 0) sum += a[len1--] - '0';
        if(len2 >= 0) sum += b[len2--] - '0';

        answer[s_idx--] = (sum % 10) + '0'; // Convert back into character before storing
        carry = sum / 10; // Get carry for next iteration
    }

  for(int i=0;i<100000;i++){
       if(answer[i]!='0')
           return &answer[i];
   }

   return &answer[99999]; 
}