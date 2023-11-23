#include <stdio.h>
#include <string.h>
#define LEN_INPUT 11

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    int i = 0;
    int a = strlen(s1);
    for(i=0;i<a;i++){
        printf("%c\n",s1[i]);
    }
    return 0;
}
