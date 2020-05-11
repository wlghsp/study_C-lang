#define _CRT_SECURE_NO_WARNINGS    // strcat 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>    // atoi, malloc, free 함수가 선언된 헤더 파일
#include <string.h>    // strcat 함수가 선언된 헤더 파일


struct student 
{
   char name[20];
   char dept[20];
   char regNum[8];
   int gender;
   int year;
   int nationality;
   int leapYear;

};


struct student list[3];
int i = 0;



int main()
{   
     
    
    printf("3명의 학생 정보를 입력하시오. \n");
    for ( i = 0; i < 3; i++)
    {
    //  int gender = 0; // 0은 남자 1은 여자 
    //  int year = 0;
    //  int nationality = 0; //0은 대한민국, 1은 외국 
    //  int leapYear = 0 ; // 0은 윤년, 1은 윤년아님. 

        printf("--------------------------------- \n");
        printf("이름 : ");
        gets(list[i].name);
        printf("학과 : ");
        gets(list[i].dept);
        printf("주민등록번호 : ");
        fgets(list[i].regNum, sizeof(list[i].regNum), stdin);

        if (list[i].regNum[6]==9 || list[i].regNum[6]==0)
        {
            list[i].gender = (list[i].regNum[6]== 9) ? 0 : 1;
            list[i].year = 18;
            list[i].nationality = 0;
        } else if (list[i].regNum[6]== 1 || list[i].regNum[6] == 2 ){
            list[i].gender = (list[i].regNum[6]== 1) ? 0 : 1;
            list[i].year = 19;
            list[i].nationality = 0;
        } else if (list[i].regNum[6]== 3 || list[i].regNum[6] == 4 ){
            list[i].gender = (list[i].regNum[6]== 3) ? 0 : 1;
            list[i].year = 20;
            list[i].nationality = 0;
        } else if (list[i].regNum[6]== 5 || list[i].regNum[6] == 6 ){
            list[i].gender = (list[i].regNum[6]== 5) ? 0 : 1;
            list[i].year = 19;
            list[i].nationality = 1;
        } else if (list[i].regNum[6]== 7 || list[i].regNum[6] == 8 ){
            list[i].gender = (list[i].regNum[6]== 5) ? 0 : 1;
            list[i].year = 20;
            list[i].nationality = 1;
        }
        int fullYear =0;
        

        printf("%s, %s년, %s, %s, %s \n", list[i].name, list[i].regNum, list[i].nationality == 0 ? "대한민국":"외국",list[i].gender == 0 ? "남자":"여자" ,  list[i].dept); 
    }
    
}