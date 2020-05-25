#include <stdio.h>
#define N 3 //입력받을 반복 횟수 

typedef struct _Student 
{
   char name[20]; //이름
   char dept[20]; //학과 
   int regNum;   //주민등록번호 
   int gender;  // 0은 남자 1은 여자 
   int year;    //4자리 연도
   int month;   //2자리 월
   int day;     //2자리 일
   int frontTwoNum; //4자리 연도 앞 2자리 숫자
   int birthDate; // 8자리 출생연도, 정렬시 사용함. 
   int nationality; //0은 대한민국, 1은 외국 
   int leapYear;   // 0은 윤년, 1은 윤년아님. 

}Student;   // typedef를 사용하여 구조체 별칭을 Student으로 정의

//변수 선언 
Student temp, list[3];
int i,j;

void mkInfobyLastNum(int lastNum) { //성별, 출생연도 앞 2자리, 국적 확인
  
    if (lastNum==9 || lastNum==0)
            {
                list[i].gender = (lastNum== 9) ? 0 : 1; //성별 0은 남자, 1은 여자
                list[i].frontTwoNum = 18;                          //4자리 연도 앞 두자리 결정
                list[i].nationality = 0;                //0은 대한민국, 1은 외국 
            } else if (lastNum== 1 || lastNum == 2 ){
                list[i].gender = (lastNum== 1) ? 0 : 1;
                list[i].frontTwoNum = 19;
                list[i].nationality = 0;
            } else if (lastNum== 3 || lastNum == 4 ){
                list[i].gender = (lastNum== 3) ? 0 : 1;
                list[i].frontTwoNum = 20;
                list[i].nationality = 0;
            } else if (lastNum== 5 || lastNum == 6 ){
                list[i].gender = (lastNum== 5) ? 0 : 1;
                list[i].frontTwoNum = 19;
                list[i].nationality = 1;
            } else if (lastNum== 7 || lastNum == 8 ){
                list[i].gender = (lastNum== 7) ? 0 : 1;
                list[i].frontTwoNum = 20;
                list[i].nationality = 1;
            }
}

void splitRegNum(int regNum, int frontTwoNum) { 
    int a = regNum / 1000000;           //주민등록번호 1번째 숫자
    int b = (regNum % 1000000)/ 100000; //주민등록번호 2번째 숫자
    int c = (regNum % 100000)/ 10000;   //주민등록번호 3번째 숫자
    int d = (regNum % 10000)/ 1000;     //주민등록번호 4번째 숫자
    int e = (regNum % 1000)/ 100;       //주민등록번호 5번째 숫자
    int f = (regNum % 100)/ 10;         //주민등록번호 6번째 숫자

    list[i].year = frontTwoNum*100+ a*10 + b; //4자리 연도 
    list[i].month = c*10 + d; //2자리 월
    list[i].day = e*10 + f; //2자리 일자
    list[i].birthDate = list[i].year*10000+list[i].month*100+list[i].day; //8자리 출생연도
}

void leapYear(int year) { //윤년 여부 결정
    if( (year%4==0 &&  year%100 !=0) ||  year%400==0)
        list[i].leapYear = 0; //0은 윤년
    else
        list[i].leapYear = 1; //1은 윤년아님
}

void oneInfoPrint() {
    printf("%s, %d년 %d월 %d일, %s, %s, %s, %s \n", list[i].name, 
    list[i].year, list[i].month, list[i].day, list[i].leapYear == 0 ? "윤년":"윤년아님",
    list[i].nationality == 0 ? "대한민국":"외국",list[i].gender == 0 ? "남자":"여자" ,  list[i].dept); 
}

void ascSort() { // 버블정렬을 활용 3명 중 생년월일이 빠를수록 먼저 출력되도록 정렬
     for ( j = 1; j < N; j++) 
     {
       for ( i = 1; i < N; i++)
       {
           if (list[i-1].birthDate > list[i].birthDate) //8자리 출생연도로 비교, 값이 크면 뒤로 감.
           {
               temp = list[i];
               list[i] = list[i-1];
               list[i-1] = temp;
           }
       }
     }
}

void allPrint() {   // 전체 학생정보 출력 
     printf("================================ \n");
     printf("입력 받은 3명의 정보를 생년월일 기준으로 오름차순으로 출력 \n");
     printf("-------------------------------- \n");
     for ( i = 0; i < N; i++) //출생연도가 이를수록 위에 위치함.
     {
        printf("%s, %d년 %d월 %d일, %s, %s, %s, %s \n", list[i].name, 
        list[i].year, list[i].month, list[i].day, list[i].leapYear == 0 ? "윤년":"윤년아님",
        list[i].nationality == 0 ? "대한민국":"외국",list[i].gender == 0 ? "남자":"여자" , list[i].dept); 
     }
     printf("\n");
     printf("-------------------------------- \n");
}

int main()
{   
    printf("3명의 학생 정보를 입력하시오. \n");
    for ( i = 0; i < N; i++) //3명의 학생정보입력 for 문 시작
    {
        printf("--------------------------------- \n");
        printf("이름 : ");
        scanf("%s",list[i].name);                 //이름 입력
        printf("학과 : ");
        scanf("%s",list[i].dept);                //학과 입력   
        printf("주민등록번호(앞 7자리만) : ");         
        scanf("%d%*c", &list[i].regNum);         //주민등록번호 앞 7자리 입력
               
        int lastNum = list[i].regNum%1000%10; //주민등록번호 7번째 숫자
        
        mkInfobyLastNum(lastNum); // 7번째숫자로 성별, 출생년도 앞 2자리, 국적 확인
        
        splitRegNum(list[i].regNum, list[i].frontTwoNum);

        leapYear(list[i].year); // 4자리 출생년도로 윤년여부 확인 
       
        oneInfoPrint();// 입력된 1명의 학생정보 출력
    
    } //3명의 학생정보입력 for문 종료
     
    ascSort(); //생년월일로 오름차순 정렬  

    allPrint(); // 정렬된 3명의 학생 정보 출력

    return 0;
    
}