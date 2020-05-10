#include <stdio.h>

struct student 
{
    char name[20];
    char major[20];
    char regNum[15];
    int year[10];
    char gender[4];
    char nationality[8];
    

};

struct student list[3];
int i;

int main()
{   
    
    printf("3명의 학생 정보를 입력하시오. \n");
    printf("----------------------------- \n");
    for ( i = 0; i < 3; i++)
    {
        printf("이름: ");
        scanf("%s", &list[i].name);
        printf("학과: ");
        scanf("%s", &list[i].major);
        printf("주민등록번호: ");
        scanf("%d", &list[i].regNum);


        switch (list[i].regNum[7])
        {
            case 9: 
                list[i].year= 18, list[i].nationality = "대한민국", list[i].gender= "남자";
                break;
            case 0:  
                list[i].year= 18, list[i].nationality = "대한민국", list[i].gender= "여자";
                break;
            case 1:  
                list[i].year= 19, list[i].nationality = "대한민국", list[i].gender= "남자";
                break;
            case 2:  
                list[i].year= 19, list[i].nationality = "대한민국", list[i].gender= "여자";
                break;
            case 3:  
                list[i].year= 20, list[i].nationality = "대한민국", list[i].gender= "남자";
                break;
            case 4:  
                list[i].year= 20, list[i].nationality = "대한민국", list[i].gender= "여자";
                break;
            case 5:  
                list[i].year= 19, list[i].nationality = "외국", list[i].gender= "남자";
                break;
            case 6:  
                list[i].year= 19, list[i].nationality = "외국", list[i].gender= "여자";
                break;
            case 7:  
                list[i].year= 20, list[i].nationality = "외국", list[i].gender= "남자";
                break;
            case 8:  
                list[i].year= 20, list[i].nationality = "외국", list[i].gender= "여자";
                break;

        
            default:
                break;
        }    

        printf("%s, %s, ", list[i].name, );
    }

}