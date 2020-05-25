#include <stdio.h>
int main(void)
{
    char num[13];
    printf("번호입력>>");
    scanf("%s", num);
    printf("19%c%c년 %c%c월 %c%c일생입니다.\n", num[0], num[1], num[2], num[3], num[4], num[5]);
    return 0;
}

