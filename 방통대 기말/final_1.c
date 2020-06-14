#include <stdio.h> //파일 포함 선행처리기, 표준입출력함수의 원형을 갖고 있는 헤더파일

int even_sum(int *gr, int); // even_sum 함수의 원형 선언
int odd_sum(int *gr, int);  // odd_sum 함수의 원형 선언

int main() { //main()함수의 시작 
    int i, sum1, sum2;  //변수 i, sum1, sum2를 정수형으로 선언
    int x[10];  //크기가 10인 배열 x 정수형으로 선언 

    for ( i = 0; i < 10; i++)   //배열 x[0]에서 x[9]에 1부터 10까지 대입 
       x[i] = i+1;                
    /* even_sum함수를 배열x와 배열x사이즈를 매개변수로 호출 */
    sum1 = even_sum(x,sizeof(x)/sizeof(int));   // 배열 크기를 구할 때는 전체 공간을 요소의 크기로 나눠줌
    /* odd_sum함수를 배열x와 배열x사이즈를 매개변수로 호출 */
    sum2 = odd_sum(x,sizeof(x)/sizeof(int));   // 배열 크기를 구할 때는 전체 공간을 요소의 크기로 나눠줌  
    
    printf("배열x의 짝수 번 요소의 합: %d\n", sum1);  // 짝수 번 요소의 합 출력 
    printf("배열x의 홀수 번 요소의 합: %d", sum2);    // 홀수 번 요소의 합 출력 

    return 0;                   //main() 함수 종료 
}

/* 배열 짝수 번 요소의 합 연산 함수 정의 */
int even_sum(int *gr, int size){ // 정수형 포인터 변수, 배열 크기를 매개변수로 받음
    int sum1 = 0;                // 변수 sum1 정수형 선언 및 초기화 
    int i;                       // 변수 i를 정수형으로 선언 
    for (i = 0; i < size; i+=2)   //for문 0부터 시작 2 씩 증가하여 짝수 번 요소만 더함. 
        sum1 += gr[i];          //배열 x[0],x[2],x[4],x[6],x[8] 합계

    return sum1;                //짝수 번 요소의 합 반환 
    
}

/* 배열 홀수 번 요소의 합 연산 함수 정의 */
int odd_sum(int *gr, int size){ // 정수형 포인터 변수, 배열 크기를 매개변수로 받음
    int sum2 = 0;               // 변수 sum2 정수형 선언 및 초기화 
    int i;                      // 변수 i를 정수형으로 선언 
    for (i = 1; i < size; i+=2)  //for문 1부터 시작 2 씩 증가하여 홀수 번 요소만 더함. 
        sum2 += gr[i];          //배열 x[1],x[3],x[5],x[7],x[9] 합계

    return sum2;                //홀수 번 요소의 합 반환 
}
