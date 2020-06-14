#include <stdio.h> //파일 포함 선행처리기, 표준입출력함수의 원형을 갖고 있는 헤더파일
#pragma warning(disable:4996) // scanf 함수 사용 경고를 출력하지 않음. 

char upper(char ch); // upper 함수의 원형 선언
char lower(char ch); // lower 함수의 원형 선언

void main() //main()함수의 시작 
{
    char in_s[50], out_s[50]; // 크기가 50인 배열 변수 in_s, out_s  선언
    char ch;                //문자형 변수 ch 선언
    int i = 0;              //정수형 변수 i 선언 및 초기화 
    printf("문자열을 입력하시오.(50자 이내) : "); //문자열 입력 안내문 출력 
    scanf("%s", in_s);          //배열 in_s에 입력을 받음. 
    ch = in_s[i];               //in_s[0]을 문자형 ch에 대입 

                            // '\0' 은 NULL이며 문자열의 끝을 의미, ch에 입력된 문자가 NULL이 아니면 반복문 while이 
    while (ch != '\0'){     // 계속되고, NULL일 경우 while문 종료  
        if(ch >= 'A' && ch <= 'Z')  
            out_s[i] = lower(ch);  //ch가 대문자라면 ch를 넣어 lower함수호출. 소문자가 된 문자를 out_s[i]에 대입
        else if(ch >= 'a' && ch <= 'z')
            out_s[i] = upper(ch);  //ch가 소문자라면 ch를 넣어 upper함수호출. 대문자가 된 문자를 out_s[i]에 대입
        else
            out_s[i] = ch; //ch가 대문자도 소문자도 아니라면 그대로 대입 
        i++;                // 변수 i의 값을 1 증가
        ch = in_s[i];       // 1이 증가 된 i번째 배열 요소를 ch에 대입   
    }
    out_s[i] = '\0'; // 배열 마지막 요소에 NULL을 대입하여 배열의 끝을 알림 
    printf("변환된 결과 ==> %s \n", out_s);  //대소문자 변환이 완료된 out_s 출력 
    
}

/* 대문자 변환 함수 정의 */
char upper(char ch) {   // 대문자 변환 함수 정의 
    return ch - 32; //ASCII 코드값 대소문자 차이 32: 대문자 변환을 위해 32를 뺀다.
}

/* 소문자 변환 함수 정의 */
char lower(char ch) {   
    return ch + 32;  //ASCII 코드값 대소문자 차이 32: 소문자 변환을 위해 32를 더한다.
}


