#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long i = left; i <= right; i++) {
        long x = i / n;
        long y = i % n;
        if (x < y) answer.push_back(y+1);
        else answer.push_back(x+1);
    }
    return answer;
}