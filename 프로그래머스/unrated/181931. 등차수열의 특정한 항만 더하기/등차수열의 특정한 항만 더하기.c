#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// included_len은 배열 included의 길이입니다.
// 등차수열 : 연속하는 두 항의 차이가 모두 일정한 수열 a =3 d =4 -> 3 7 11 15 19 
// 즉, 처음에 3을 주고 항이 늘어날때마다 4씩 더하라는 의미
int solution(int a, int d, bool included[], size_t included_len) {
    int answer = 0;
    for(int i = 0; i < included_len; i++){
        if(included[i] == true){
            answer+= a + (d * i);
        }
    }
    return answer;
}
int main(){
    int a;
    int d;
    bool included;
    int included_len;
    scanf("%d %d %d %d",a,d,included,included_len);
    if(a <= 100 && d <=100 && included_len <=100 ){
        int result = solution(a,d,included,included_len);
        printf("%d",result);
    }else{
        printf("제한사항을 초과하는 값을 입력받았습니다.");
    }
    return 0;
}