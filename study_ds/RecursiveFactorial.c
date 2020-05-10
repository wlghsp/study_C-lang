#include <stdio.h>

int Factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * Factorial(n-1);
}

int main(void)
{
    printf("1! = %lu \n", Factorial(1));
    printf("2! = %lu \n", Factorial(2));
    printf("3! = %lu \n", Factorial(3));
    printf("4! = %lu \n", Factorial(4));
    printf("9! = %lu \n", Factorial(9));
    return 0;

}