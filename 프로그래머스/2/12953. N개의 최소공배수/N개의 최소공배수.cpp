#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int A, int B){
    int a = max(A, B);
    int b = min(A, B);
    
    while (a % b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    
    return b;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        int GCD = gcd(answer, arr[i]);
        int LCM = (answer * arr[i]) / GCD;
        answer = LCM;
    }
    return answer;
}