#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이동 최소화
// 이동하려는 거리 = N
int solution(int n)
{
    int ans = 0;
    while (n > 0) {
        if (n % 2 == 0) {
            n /= 2;  
        } else {
            n -= 1; 
            ans++;
        }
    }
    // 사용해야 하는 건전지 사용량의 최소값
    return ans;
}