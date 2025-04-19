#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    int n = citations.size();
    int hIndex = 0;
    for (int i = 0; i < n; i++) {
        hIndex = n - i;
        if (hIndex <= citations[i]) {
            answer = hIndex;
            break;
        }   
    }
    return answer;
}