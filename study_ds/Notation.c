#include <stdio.h>

int main(void)
{
    int num1 = 0xA7, num2 = 0x43; //10진수로 초기화 하고 있음
    int num3 = 032, num4 = 024;

    printf("0xA7의 10진수 정수 값: %lu \n", num1);
    printf("0x43의 10진수 정수 값: %lu \n", num2);
    printf(" 032의 10진수 정수 값: %lu \n", num3);
    printf(" 024의 10진수 정수 값: %lu \n", num4);


    printf("%lu- %lu = %lu \n", num1, num2, num1-num2);
    printf("%lu+ %lu = %lu \n", num3, num4, num3+num4);

    return 0;
}