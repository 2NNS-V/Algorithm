#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int num = brown + yellow;
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0 && num / i >= i) {
            if ((num/i - 2) * (i - 2) == yellow) {
                answer.push_back(num/i);
                answer.push_back(i);
                break;
            }
            
        }
    }
    return answer;
}