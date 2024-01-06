#include <stdio.h>
int main() {
    int N, cnt=0;
    scanf("%d", &N);
    int init = N;
    while(1) {
        N = (N / 10 + N % 10) % 10 + N % 10 * 10; // (N의 10의 자리 수+1의 자리수)%10은 다음 N의 1의자리수, N의 1의 자리수 * 10= 다음 N의 10의 자리수
        cnt++;
        if (N == init) {
            printf("%d", cnt);
            break;
        }
    }
    return 0;
}
