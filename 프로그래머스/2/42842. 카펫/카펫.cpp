#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

// 약수 구하기


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int x, y; // x: 가로, y: 세로
    for (int i = yellow; i >= sqrt(yellow); i--) {
        if (yellow % i == 0) {
            x = i + 2;
            y = (yellow / i) + 2;
        }
        
        if ((x * y) - yellow == brown) break;
    }
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}