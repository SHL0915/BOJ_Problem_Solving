#include <stdio.h>

int main(void){
    int N, count = 0; // 타로가 지불할 돈 N, 잔돈의 개수 count
    scanf("%d",&N);
    N = 1000 - N; // 거스름돈으로 N을 초기화
    count += (N/500);
    N = N % 500;
    count += (N/100);
    N = N % 100;
    count += (N/50);
    N = N % 50;
    count += (N/10);
    N = N % 10;
    count += (N/5);
    N = N % 5;
    count += N;    
    printf("%d",count);
    return 0;
}