#include <stdio.h>
// atoi
#include <stdlib.h>

// declare the struct for get student's information
struct person
{
   char name[50];   // student's name
   char study[50];   // student's department
   char id[50];   // Resident registration number
   char info[100];   // information of student for show
   int birth;      // birthday for sorting
} student[3];

// birth year - prepared for sort & leap year
int born(char *s);
// country
int country(char *s);
// sex
int sex(char *s);
// leap year
int yun(int year);

// procedures of below list are served for sorting function
void proc_swap(struct person *a, struct person *b);
void quickSort(struct person *nodes, int low, int high);

void main()
{
   int i;      // loop counter
   int j;      // loop counter
   int iBorn;   // year of birth
   int iMon;   // month of birth
   int iDay;   // day of birth
   
   char sBorn[50];   // container for calculating birthday
   char str[50];   // temp container for get student's sex & country
   
   char *sCountry;   // pointer of country string
   char *sSex;      // pointer of sex string
   char *sYun;      // pointer of leap year string
   
   printf("3명의 학생 정보를 입력하시오.\n");
   printf("------------------------------\n");
   for (i = 0; i < 3; i++){
      // resets the list of sBorn
      for (j = 0; j < 50; j++)
         sBorn[j] = 0;
      
      // gets the student's information
      printf("이름: ");
      scanf("%s", student[i].name);
      printf("학과: ");
      scanf("%s", student[i].study);
      printf("주민등록번호: ");
      
      // routine of get birthday with starmarks over 7 length
      j = 0;
      while (1)
      {
         if (kbhit())
         {
            student[i].id[j] = getch();
            if (j < 7)
               printf("%c", student[i].id[j]);
            else
               printf("*");
            
            j++;
            if (j > 12)
               break;
         }
      }
      student[i].id[j] = 0;
      
      // get student's sex
      strncpy(str, &student[i].id[6], 1);
      if (sex(str) > 0)
         sSex = "남자";
      else
         sSex = "여자";

      // get student's leap year of birth year
      strncpy(sBorn, &student[i].id[0], 2);
      iBorn = born(str);
      iBorn = iBorn + atoi(sBorn);
      if (yun(iBorn) > 0)
         sYun = "윤년";
      else
         sYun = "윤년아님";
      
      // get student's country
      strncpy(sBorn, &student[i].id[2], 2);
      iMon = atoi(sBorn);
      strncpy(sBorn, &student[i].id[4], 2);
      iDay = atoi(sBorn);
      if (country(str) > 0)
         sCountry = "외국";
      else
         sCountry = "대한민국";
         
      // reserved list for sorting that by birthday
      itoa(iBorn, sBorn, 10);
      strncpy(&sBorn[4], &student[i].id[2], 4);
      student[i].birth = atoi(sBorn);
   
      // print result of student's information what is inputted
      sprintf(student[i].info, "%s, %d년 %02d월 %02d일, %s, %s, %s, %s", student[i].name, iBorn, iMon, iDay, sYun, sCountry, sSex, student[i].study);
      printf("\n%s\n", student[i].info);
      if (i < 2)   
         printf("------------------------------\n");
      else
         printf("==============================\n");
   }
   
   printf("입력 받은 3명의 정보를 생년월일 기준으로 오름차순으로 출력\n");
   printf("------------------------------\n");
   // sorting students by birthday
   quickSort(student, 0, 2);
   for (i = 0; i < 3; i++)
   {
      // print student's information what is sorted
      printf("%s\n", student[i].info);
   }
}

// swap struct
void proc_swap(struct person *a, struct person *b)
{
   struct person temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

// routine of sorting ASC
void quickSort(struct person *nodes, int low, int high)
{
   int pivot, i, j, temp;
   if (low < high)
   {
      pivot = low;
      i = low;
      j = high;
      
      while (i<j)
      {
         while (nodes[i].birth <= nodes[pivot].birth && i <= high)
         {
            i++;
         }
         while (nodes[j].birth > nodes[pivot].birth && j >= low)
         {
            j--;
         }
         
         if (i<j)
         {
            proc_swap(&nodes[i], &nodes[j]);
         }
      }
      
      proc_swap(&nodes[j], &nodes[pivot]);
      quickSort(nodes, low, j-1);
      quickSort(nodes, j+1, high);
   }
}

// return value presents 0 to woman, 1 to man 
int sex(char *s)
{
   int n = atoi(s);

   switch(n)
   {
      case 1: return 1;
      break;
      case 3: return 1;
      break;
      case 5: return 1;
      break;
      case 7: return 1;
      break;
      case 9: return 1;
      break;
      default: return 0;
   }
}

// gets the birth year
int born(char *s)
{
   int n = atoi(s);
   
   switch(n)
   {
      case 1: return 1900;
      break;
      case 2: return 1900;
      break;
      case 5: return 1900;
      break;
      case 6: return 1900;
      break;
      case 3: return 2000;
      break;
      case 4: return 2000;
      break;
      case 7: return 2000;
      break;
      case 8: return 2000;
      break;
      default: return 1800;
   }
}

// return value presents 0 to native, 1 to foreigner
int country(char *s)
{
   int n = atoi(s);
   
   switch(n)
   {
      case 1: return 0;
      break;
      case 2: return 0;
      break;
      case 3: return 0;
      break;
      case 4: return 0;
      break;
      case 9: return 0;
      break;
      case 0: return 0;
      break;
      default: return 1;
   }
}

// calculate the year whether leap year or not
int yun(int year)
{
   if (year % 400 == 0 )
      return 1;
   else if ((year % 4 == 0) && (year % 100 != 0))
      return 1;
   else
      return 0;
}