#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 3 //입력받을 반복 횟수 

typedef struct student 
{
   char name[20];   // 이름 
   char dept[20];   // 학과 
   char regNum[20];   // 주민등록번호 
   
   int country; // 국가 체크 1 : 대한민국 
   int gender; // 성별 체크 1 : 남자 
   int year; // 연도 
   int month; // 월 
   int day;   // 일 
   int leapYear; // 윤년 여부 1 : 윤년 
   
}Student;

int vaildater(const char * tmpRegNum, char * stdRegNum); // 유효성 체크 
void mkStudentInfoByRegNum(Student * std);   // 주민번호로 정보 추출
void mkStudentInfoByLastRegNum(int num, Student * std); // 주민번호 뒷자리 첫번째 자리로 정보 추출 
void print(Student * std);   // 학생정보출력 
void ascSort(Student std[N]);   // 오름차순정렬 

int main(){
   int i = 0, validator = 1; // i : for문 loop를 돌리기 위한 변수 , validator : while loop를 컨트롤 하는 변수 
   char tmp[20]; // 주민번호를 임시로 받기위한 변수 
   Student std[N]; // 구조체 Student 배열로 선언 
   
   printf("%d명의 학생정보를 입력하세요\n", N); //프롬프트 
   
   for(i = 0; i < N; i++){ //i의 변수가 N보다 작을때 루프가 종료되면 i를 1증가 
      printf("------------------------------------\n");
      validator = 1;
      
      printf("이름을 입력하세요 : ");
      scanf( "%s" , std[i].name ); // 이름을 입력받는다. 
      printf("학과를 입력하세요 : ");
      scanf( "%s" , std[i].dept ); // 학과를 입력받는다.  
      printf("주민등록번호를 입력하세요. ex) 990210-1xxxxxx : "); 
      do{    // 주민등록번호 입력 
         scanf( "%s" , tmp );
         validator = vaildater(tmp, std[i].regNum ); // vaildater함수 호출한후 validator 변수에 return 값을 저장 
         if(validator == 1){
            printf("양식에 맞게 입력해주세요 ex) 990210-1xxxxxx : ");
         }
      } while(validator);
      
      mkStudentInfoByRegNum(&std[i]);
      print(&std[i]);
   }
   
   printf("====================================\n");
   printf("오름차순 정렬 이후 출력\n");
   
   ascSort(std);
   for(i= 0; i<N; i++){
      print(&std[i]);
   }
   
   return 0; 
} 


// 주민등록번호 유효성 검사
int vaildater(const char * tmpRegNum, char * stdRegNum){
   int returnVal = 1; 
   
   if(strchr(tmpRegNum,'-') != NULL){
      if( strlen(tmpRegNum) == 14 ){
         strcpy(stdRegNum, tmpRegNum);
         returnVal = 0;
      }
   }
   
   return returnVal;
}

//주민번호로 정보 추출
void mkStudentInfoByRegNum(Student * std){
   // 주민번호 '-' 기준으로 분리 
   char * srn[2];
   srn[0] = strtok((*std).regNum, "-");
   srn[1] = strtok(NULL, "-");
   
   //연도 추출
   char tmpYear[3];
   char tmpMonth[3];
   char tmpDay[3];
   
   // srn[0] = "921207"  ( char * ) &srn[0][2]
   
   strncpy(tmpYear,srn[0], 2); // "92"
   strncpy(tmpMonth,&srn[0][2], 2); // "12"
   strncpy(tmpDay,&srn[0][4], 2); // "07"
   
   (*std).year = atoi(tmpYear); //문자열을 -> 정수형으로 변경 
   (*std).month = atoi(tmpMonth);
   (*std).day = atoi(tmpDay);
   
   //윤년체크
   if( ((*std).year % 4 == 0  && !( (*std).year % 100 == 0) ) || (*std).year % 400 == 0 ){ // 윤년이 되는 조건 
      (*std).leapYear = 1;  // 1이면 윤년 
   }else{
      (*std).leapYear = 0;   // 0이면 윤년이 아님 
   }
   
   //주민번호 뒷자리 첫번째 숫자로 정보 추출
   // 921207-1
   mkStudentInfoByLastRegNum(srn[1][0] - '0', std); // mkStudentInfoByLastRegNum 호출 
   // '1' == 49 - '0' == 48 -> 1
}

// 주민번호 뒷자리 첫번째 숫자로 정보 추출 
void mkStudentInfoByLastRegNum(const int num, Student * std){
   
   int country = 0;   // 1은 대한민국 그 이외의 숫자는 외국 
   int gender = 0;      // 1은 남자 그 이외의 숫자는 여자 
   int tmpYear = 0;

   switch(num){
      case 1 :
      country = 1;
      gender = 1;
      tmpYear = 1900;
      break;
      
      case 2 :
      country = 1;
      gender = 2;
      tmpYear = 1900;
      break;                     
      
      case 3 :
      country = 1;
      gender = 1;
      tmpYear = 2000;
      break;
      
      case 4 :
      country = 1;
      gender = 2;
      tmpYear = 2000;
      break;
      
      case 5 :
      country = 2;
      gender = 1;
      tmpYear = 1900;
      break;
      
      case 6 :
      country = 2;
      gender = 2;
      tmpYear = 1900;
      break;
      
      case 7 :
      country = 2;
      gender = 1;
      tmpYear = 2000;
      break;
      
      case 8 :
      country = 2;
      gender = 2;
      tmpYear = 2000;
      break;
      
      case 9 :
      country = 1;
      gender = 1;
      tmpYear = 1800;
      break;
      
      case 0 :
      country = 1;
      gender = 2;
      tmpYear = 1800;
      break;
   }
   
   (*std).country = country;
   
   (*std).gender = gender;
   
   (*std).year += tmpYear;
   
}

// 정보 출력 라인으로  
void print(Student * std){
   char tmpMonth = (*std).month < 10 ? '0' : '';
   char tmpDay = (*std).day < 10 ? '0' : '';
   char * tmpLeapYear = (*std).leapYear == 1 ? "윤년" : "윤년아님";
   char * gender =  (*std).gender == 1 ? "남자" : "여자";
   char * country = (*std).country == 1 ? "대한민국" : "외국";

   printf("%s, %d년 %c%d월 %c%d일, %s, %s, %s, %s\n",(*std).name, (*std).year, tmpMonth, (*std).month, tmpDay, (*std).day, tmpLeapYear, country, gender, (*std).dept);

}


void ascSort(Student std[N]){
   
   if(N > 1){ // 입력한 학생수가 1명이면 비교할 대상이 없으니까 정렬을 하지 않음
   
      int year = std[0].year;
      int month = std[0].month;
      int day = std[0].day;
      int i = 0;
   
      for(i = 1; i < N; i++){
         
         if(year > std[i].year){
            Student tmp = std[i-1];
            std[i-1] = std[i];
            std[i] = tmp;
         }
      }
         
   }
}
