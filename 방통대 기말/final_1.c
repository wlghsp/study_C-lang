#include <stdio.h> //파일 포함 선행처리기
int even_sum(int *gr, int);
int odd_sum(int *gr, int);

int main() { //main()함수의 시작 
    int i, sum1, sum2;  //변수 i, sum1, sum2를 정수형으로 선언
    int x[10];

    for ( i = 0; i < 10; i++)   //배열 x에 1부터 10까지 대입 
       x[i] = i+1;

    sum1 = even_sum(x,10);
    sum2 = odd_sum(x,10);
    
    printf("배열x의 짝수 번 요소의 합: %d\n", sum1);
    printf("배열x의 홀수 번 요소의 합: %d", sum2);

    return 0;
}


int even_sum(int *gr, int size){ //배열 짝수 번 요소의 합 계산 함수
    int sum1 = 0;
    int i;
    for (i = 0; i < size; i+=2) 
        sum1 += gr[i];          //배열 x[0],x[2],x[4],x[6],x[8] 합계

    return sum1;
    
}


int odd_sum(int *gr, int size){ //배열 홀수번 요소의 합 계산 함수
    int sum2 = 0;
    int i;
    for (i = 1; i < size; i+=2)
        sum2 += gr[i];          //배열 x[1],x[3],x[5],x[7],x[9] 합계

    return sum2;
}
