#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while (0 < n) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n -= 1;
            ans++;
        }
    }

    return ans;
}