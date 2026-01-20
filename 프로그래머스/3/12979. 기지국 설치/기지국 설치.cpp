#include <iostream>
#include <vector>
using namespace std;
// 커버된 곳과 안된 곳 분리
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int cover = w * 2 + 1;
    
    int prev = 1; // 아직 커버 안된 위치
    for (auto s: stations) {
        int left = s - w;
        
        if (prev < left) {
            int gap = left - prev;
            answer += (gap + cover - 1) / cover;
        }
        
        prev = s + w + 1;
    }
    
    if (prev <= n) {
        int gap = n - prev + 1;
        answer += (gap + cover - 1) / cover;
    }
    return answer;
}