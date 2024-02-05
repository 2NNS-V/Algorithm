#include <stdio.h>

int main() {
    int n, result=0;
    scanf("%d", &n);
    for (int i=1;i<n+1;i++){
        result += i;
    }
    printf("%d", result);
}