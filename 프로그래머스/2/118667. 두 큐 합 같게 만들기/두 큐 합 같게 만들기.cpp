#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 최소 연산 횟수 구하기
int solution(vector<int> queue1, vector<int> queue2) {
    int n = queue1.size();
    
    vector<int> arr;
    long long sum1 = 0, sum2 = 0;
    for (int i =0; i < n; i++) {
        arr.push_back(queue1[i]);
        sum1 += queue1[i];
    }
    for (int i =0; i < n; i++) {
        arr.push_back(queue2[i]);
        sum2 += queue2[i];
    }
    long long total = sum1 + sum2;
    if (total % 2) return -1;
    long long target = total / 2;
    
    long long curr = sum1;
    int s = 0, e = n;
    int cnt = 0;
    
    while (cnt <= 3 * n) {
        if (curr == target) return cnt;
        else if (curr > target) {
            if (s >= 2*n) break;
            curr -= arr[s++];
        }
        else {
            if (e >= 2*n) break;
            curr += arr[e++];
        }
        cnt++;
    }   
    
    return -1;
    
}