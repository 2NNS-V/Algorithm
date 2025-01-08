#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    while (n) {
        int tmp = n % 10;
        answer += tmp;
        n /= 10;
    }
    return answer;
}