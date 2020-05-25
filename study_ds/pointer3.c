#include <stdio.h>

int change(int *);      //change 함수의 원형 선언

void main() {
    int a = 10;                             //함수의 매개변수인 k가  포인터이므로 
    int *p= &a;                             // change 함수를 호출할 때 인자로 a 대신 a를 
    printf("함수 호출 이전의 a : %d\n", a);     // 포인트하고 있는 p를 매개변수로 전달
    change(p);
    printf("함수 호출 이후의 a : %d\n", a);
}

int change(int *k)
{
    *k = *k + *k; 
    return 0; 
}