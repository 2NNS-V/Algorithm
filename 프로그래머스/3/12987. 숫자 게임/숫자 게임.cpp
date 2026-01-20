#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int start = 0, end = A.size() - 1;
    for (int i = 0; i < B.size(); i++) {
        if (A[start] < B[i]) {
            start++;
            answer++;
        }
    }
    return answer;
}