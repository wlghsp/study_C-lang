#include <stdio.h> //파일 포함 선행처리기, 표준입출력함수의 원형을 갖고 있는 헤더파일
#pragma warning(disable:4996) // scanf 함수 사용 경고를 출력하지 않음. 

struct entry {          // entry형 구조체 정의 
    char fname[20];     //성을 입력 받을 크기 20의 문자형 배열 변수 fname 선언
    char lname[20];     //이름을 입력 받을 크기 20의 문자형 배열 변수 lname 선언
    char phone[10];     //전화번호를 입력 받을 크기 20의 문자형 배열 변수 phone 선언
};
struct entry list[4];      // 크기 4의 entry형 구조체 배열 list 선언 
int i;                     // 정수형 변수 i 선언 

void main()  //main()함수의 시작 
{
   for ( i = 0; i < 4; i++)  //4명의 정보를 입력 받을 for문 
   {
       printf("Enter first name : ");  // 성 입력 안내문 출력 
       scanf("%s", list[i].fname);     // 입력된 성을 구조체 배열 i번째 요소의 fname에 저장
       printf("Enter last name : ");   // 이름 입력 안내문 출력 
       scanf("%s", list[i].lname);     // 입력된 이름을 구조체 배열 i번째 요소의 lname에 저장
       printf("Enter phone number : "); // 전화번호 입력 안내문 출력 
       scanf("%s", list[i].phone);   // 입력된 전화번호를 구조체 배열 i번째 요소의 phone에 저장
       printf("\n");        // 줄 바꿈 
   } 
    printf("\n");  // 줄 바꿈 
    for ( i = 0; i < 4; i++) //입력 받은 4명의 정보를 출력할 for문 
    {
        printf("Name : %s %s", list[i].fname, list[i].lname); // 성 과 이름 출력
        printf("\t\tPhone : %s \n", list[i].phone);           // 2번의 탭으로 공간을 띄운 후 전화번호 출력 후 개행   
    }
}
