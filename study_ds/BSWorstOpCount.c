#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
    int first = 0;
    int last = len -1;
    int mid;
    int opCount = 0;

    while (first <= last)
    {
        mid =  (first + last) / 2;

        if (target == ar[mid])
        {
            return mid;
        }
        else
        {
            if (target < ar[mid])
                last = mid - 1;
            else
                first = mid + 1;
            
        }
        opCount += 1; //비교연산의 횟수 1 증가
    } 
    printf("비교연산횟수: %d \n", opCount); //탐색실패 시 연산횟수 출력
    return -1;
    
}

int main(void)
{
    int arr1[500]  = {0,}; //모든 요소 0으로 초기화 
    int arr2[5000]  = {0,}; //모든 요소 0으로 초기화
    int arr3[50000]  = {0,}; //모든 요소 0으로 초기화
    int idx;

    //배열 arr1을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
    idx = BSearch(arr1, sizeof(arr1)/sizeof(int), 1);
    if(idx == -1)
        printf("탐색 실패 \n\n");
    else
        printf("타겟 저장 인데스: %d \n", idx);
    
    //배열 arr2를 대상으로, 저장되지 않은 정수 2을 찾으라고 명령
    idx = BSearch(arr2, sizeof(arr2)/sizeof(int), 2);
    if(idx == -1)
        printf("탐색 실패 \n\n");
    else
        printf("타겟 저장 인데스: %d \n", idx);
    
     //배열 arr3를 대상으로, 저장되지 않은 정수 3을 찾으라고 명령
    idx = BSearch(arr3, sizeof(arr3)/sizeof(int), 3);
    if(idx == -1)
        printf("탐색 실패 \n\n");
    else
        printf("타겟 저장 인데스: %d \n", idx);
    
    return 0;
}
