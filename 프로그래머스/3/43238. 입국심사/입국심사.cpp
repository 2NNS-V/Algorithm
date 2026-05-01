#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool avail(long long mid, int n, vector<int> times) {
    long long sum = 0;
    for (int i = 0; i < times.size(); i++) {
        sum += mid / times[i];
        
        if (sum >= n) return true;
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long low = 1;
    long long high = (long long)times[times.size() - 1] * n;
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        
        // 모든 사람이 mid 시간 안에 심사를 받을 수 있는지 확인
        if (avail(mid, n, times)) { 
            high = mid - 1;
            answer = mid;
        }
        else low = mid + 1;
    }
    return answer;
}