#include <stdio.h>

int main() {
    double A, B;
    scanf("%lf", &A);
    scanf("%lf", &B);
    
    printf("%.13lf", A/B);
}

// 부동소수점 관련 문제
// float (32bit/4byte) : 10^(-7)
// double(64bit/8byte) : 10^(-15)
// 오차를 줄이려면 비트수가 큰 것 사용