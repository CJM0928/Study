#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* bin1, const char* bin2) {
    int len1 = strlen(bin1);
    int len2 = strlen(bin2);
    int n1 = len1;
    int n2 = len2;
    int maxlen = (len1>=len2) ? len1 : len2;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((maxlen+1)*sizeof(char));
    char* answer_1 = (char*)malloc((maxlen+1)*sizeof(char));
    char* str1 = (char*)malloc((maxlen+1)*sizeof(char));
    char* str2 = (char*)malloc((maxlen+1)*sizeof(char));
    strcpy(str1,bin1);
    strcpy(str2,bin2);
    // 길이가 작은 문자열에 앞의 빈칸에 0을 채워주기 위한 작업.
    while (maxlen != len1) {
    int i = 0;
    for (i = 0; i < maxlen; i++) {
        if (str1[i] == '\0') {
            str1[i] = '0';
        }
    }
    len1++; // 길이 맞추기 위해 한 번씩 증가시켜주기
    }
    while (maxlen != len2) {
    int i = 0;
    for (i = 0; i < maxlen; i++) {
        if (str2[i] == '\0') {
            str2[i] = '0';
        }
    }
    len2++; // 길이 맞추기 위해 한 번씩 증가시켜주기
    }
    // 길이 맞춰줬으므로 이진수를 계산해주기만 하면된다.
    // answer_1에 0부터해서 넣고,
    // 나중에 answer에 넣을때는 맨뒤에부터 출력하는 즉 반대로 출력해서 맞춘다.
    int idx = 0;
    int temp = 0; // 만약 더해서 2 이상이라면 앞에 1을 더해주는 임시변수
    int num1 = str1[n1] - '0';
    int num2 = str2[n2] - '0';
    int num = 0;
    while(1){
        if(temp + num1 + num2 < 2){
            num = temp + num1 + num2;
            temp = 0;
        }else if(temp + num1 + num2 >= 2){
            num = temp + num1 + num2 - 2; // num이 2를 초과할때
            temp = 1; // 임시변수를 1을 만들어주고 다음 if문에서 내려올때 활용
        }
        
        answer_1[idx++] = num + '0'; // 정수인 num을 문자화해서 인덱스에 삽입.
        
        if(n1 == 0 && n2 == 0 && temp == 0){ // 더이상 입력할 이진수가 없다면 반복문 탈출
            break;
        }
        // n1과 n2가 마이너스로 내려가지 못하게 방지
        if(n1 > 0){
            num1 = str1[--n1] - '0';
        }else{
            num1 = 0;
        }
        if(n2 > 0){
            num2 = str2[--n2] - '0';
        }else{
            num2 = 0;
        }
    }
    for(int i = 0; i < idx; i++){ // answer_1은 현재 뒤에있어야할 이진수가 앞에 놓여있으니 반대로 뒤집기.
        answer[i] = answer_1[idx -1 - i];
    }
    answer[idx-1] = '\0';
    return answer;
}