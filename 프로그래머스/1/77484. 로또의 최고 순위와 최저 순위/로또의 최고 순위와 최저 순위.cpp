#include <string>
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

int calc_score(int n) {
    int score;
    switch(n) {
        case 6: 
            score = 1;
            break;
        case 5:
            score = 2;
            break;
        case 4:
            score = 3;
            break;
        case 3:
            score = 4;
            break;
        case 2:
            score = 5;
            break;
        default: 
            score = 6;
            break;
    }
    return score;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int max_num, min_num;
    int cnt = 0; // 당첨 개수
    
    // 동일한 거 찾기
    int zero = 0;
    for (int i = 0; i < win_nums.size(); i++) {
        for (int j = 0; j < lottos.size(); j++) {
            if (win_nums[i] == lottos[j]) cnt++;
        }
        if (lottos[i] == 0) zero++;
    }
    max_num = cnt + zero;
    min_num = cnt;
    cout << max_num << " " << min_num << endl;
    
    answer.push_back(calc_score(max_num));
    answer.push_back(calc_score(min_num));
    
    return answer;
}