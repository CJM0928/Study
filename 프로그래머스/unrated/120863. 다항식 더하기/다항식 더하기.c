#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// strtok로 분할하는 방식은 배열도 추가해야하고 포인터도 고려해야해서 배제한다.
char* solution(const char* polynomial) {
    int length = strlen(polynomial);
    int x = 0;
    int num = 0;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((length + 1) * sizeof(char));
    for(int i = 0; i < length; i++){
        if(polynomial[i] == 'x'){ // x가 있을때
            if(polynomial[i-1] == ' '){ // x앞에숫자가 없을때 1을 더해준다.
                x += 1;
            }else if(i==0){// x앞에숫자가 없을때 1을 더해준다.
                x += 1;
            }else if(('1' <= polynomial[i-2] && polynomial[i-2] <= '9') && ('0' <= polynomial[i-1] && polynomial[i-1] <= '9')){ //x앞에 두자리 숫자라면
                int temp = ((polynomial[i-2] - '0') * 10) + (polynomial[i-1] - '0');
                x += temp;
            }else{ // x앞에 한자리 수
                x += (polynomial[i-1] - '0'); 
            }
        }else if(('0' <= polynomial[i] && polynomial[i] <= '9' ) && polynomial[i+1] != 'x'){ // 뒤에x가없는 상수만 고려
            if((polynomial[i-1] == ' ' || i == 0) && (polynomial[i+1] == ' ' || i == (length -1))){ // " 7 " 또는 "7" 을 고려한 if문 이면서 상수가 한자리인경우
                num += (polynomial[i] - '0'); 
            }else if(('1' <= polynomial[i-1] && polynomial[i-1] <= '9') && ('0' <= polynomial[i] && polynomial[i] <= '9')){ // 두자리 상수를 고려
                int temp = ((polynomial[i-1] - '0') * 10) + (polynomial[i] - '0');
                num += temp;
            }
        }
    }
    // answer에 값을 입력할건데 이것은 sprintf를 사용해본다.
    if(x > 0 && num > 0){ //x와 상수둘다 존재할경우
        if(x > 1){ // x앞에 수가 존재할경우
            sprintf(answer,"%dx + %d",x,num);
        }else if(x == 1){ // x앞에 수가 존재하지않을경우
            sprintf(answer,"x + %d",num);   
        }
    }else if(x>0 && num == 0){ // x는 존재하지만 상수는 존재하지않는경우
        if(x > 1){ // x앞에 수가 존재할경우
            sprintf(answer,"%dx",x);
        }else if(x == 1){ // x앞에 수가 존재하지않을경우
            answer = "x";   
        }
    }else{ //x가 없고 상수만 존재할때
        sprintf(answer,"%d",num);
    }
    return answer;
}