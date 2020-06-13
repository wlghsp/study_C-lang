#include <stdio.h> //파일 포함 선행처리기, 표준입출력함수의 원형을 갖고 있는 헤더파일
#pragma warning(disable:4996) // scanf 함수 사용 경고를 출력하지 않음. 

void main() //main()함수의 시작 
{
    int n, count;   //정수형 변수 n, count 선언 
    float avg, d, sum = 0;  //실수형 변수 avg, d, sum 선언 및 초기화 
    float list[100];        // 크기 100의 실수형 배열 list 선언 
    printf("평균을 내고자 하는 데이터의 개수는? ");  // 데이터의 개수 입력 안내문 출력
    scanf("%d", &n);                        // 데이터의 개수 입력 
    for (count = 0; count< n; ++count)     //n개의 데이터 입력 받는 for문 
    {
        printf("i = %d x =", count+1);     //데이터 입력 안내문 출력
        scanf("%f", &list[count]);         // 데이터 입력 받음
        sum += list[count];                // 데이터를 합함. 
    }
    avg = sum / n; // 평균 연산 
    printf("The average is %5.2f \n", avg); //평균값 출력 
    
    for ( count = 0; count < n; ++count) //n개의 데이터 값 및 표준 편차를 출력하는 for문  
    {
        d= list[count] - avg; //표준편차는 각 데이터에서 평균을 제한다. 
        printf("i = %d x = %5.2f d=%5.2f \n", count + 1, list[count], d); //각 데이터 값 및 표준편차 출력 
    }   
}