#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    if (n <= 3) return n;
    
    int n2 = 2, n3 = 3;
    for (int i = 4; i <= n; i++) {
        answer = (n2 + n3) % 1234567;
        n2 = n3;
        n3 = answer;
    }
    return answer;
}