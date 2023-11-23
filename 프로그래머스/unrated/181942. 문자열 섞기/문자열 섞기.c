#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>  // 대,소문자 변환 함수 사용시 사용하는것
#include <string.h>

//error: expected identifier or '(' : 오류는 함수의 이름을 바꿔줘야한다 (변수명x)
//error: expected expression : 형변환 오류 이므로 형변환 확인  
//warning: comparing a pointer to a null character constant : 포인터 오류 (포인터로 수정)

// 문자열(string) : 문자(character) 의 배열(array)
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

// 두 문자열을 번갈아가면서 만드는 함수
char* solution(const char* str1, const char* str2) 
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    // 리턴할 answer배열에 문자 str1[i] str2[i]의 배열값 입력, 조건은 size까지
    int length = strlen(str1); 
    //strlen: const char* 타입의 문자열을 받아서 해당 문자열의 길이를 반환하는 함수입니다.
    char* answer = (char*)malloc((2 * length) * sizeof(char));
    memset(answer, 0, (2 * length) * sizeof(char) );
    // 문자열 길이 str1 + str2 합친길이 
    int index = 0;
    for (int i = 0; i < length; i++)
	{
		//첫번째 문자열의 i값 입력
		answer[index++] = str1[i];
		//두번째 문자열 i값 입력
		answer[index++] = str2[i];
	}
    // strlen 사용 후 NULL 선언을 해주지 않으면
    // 잘못된 값을 출력 할 수 있기때문에 반드시 해줘야한다.
	answer[index] = '\0';

	return answer;
}
int LowerCase(char* str1, char* str2) 
{
    // 입력된 str1,str2가 NULL이 될때까지 소문자인지 확인 
    // 둘중 하나라도 대문자가 발견되면 0을 반환
    while(*str1 != '\0' && *str2 != '\0') // [ \0 이 아닌 '\0' 으로 써야한다. ]
    {
        if(!islower(*str1) || !islower(*str2))\
        {
            return 0;
        }
        str1++;
        str2++;
    } 
    // str1과 str2의 size가 동일한지 확인 하나라도 다르면 0을 반환
    if(*str1 != '\0' || *str2 != '\0')
    {
        return 0;
    }
    // 모든조건에 해당되지 않는다면 1을 반환
    return 1;
}
int main()
{
    //길이는 10 이하
    const int Max_length = 10;
    // 입력할 문자 str1 str2 선언 및 제한사항 (길이 10이하)
    char* str1 = (char*)malloc(Max_length * sizeof(char));
    char* str2 = (char*)malloc(Max_length * sizeof(char));
    
    // str1 str2에 값 입력
    scanf("%s %s", str1, str2);
    // 입력된 str1 , str2의 값 대문자 및 size 확인
    if(LowerCase(str1,str2))
    {
    char* result = solution(str1,str2);  // solution 함수 호출
    printf("%s",result);                 // solution 함수 결과 출력
    free(result);  // 메모리 초기화
    }
    else
    {
        printf("대문자 또는 다른길이 발견");
    }
    //문자열 동적 할당 메모리 초기화
	free(str1);
	free(str2);
    return 0;
}