#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 가로 길이는 세로와 같거나 길다. -> 약수 중에 ?
    int total = brown + yellow;
    for (int i = 1; i <= total / 2; i++) {
        if (total % i == 0 && total / i >= i) {
            if ((total / i - 2)  * (i - 2) == yellow) {
                answer.push_back(total/i);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}