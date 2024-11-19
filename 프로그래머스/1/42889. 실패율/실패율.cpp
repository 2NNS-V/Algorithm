#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<double,int> a, pair<double,int> b){
    if(a.first==b.first)return a.second<b.second;
    else return a.first>b.first;

}

// N = 전체 스테이지 개수, states = 멈춰있는 스테이지 번호 배열
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    deque<pair<double, int>> tmp(N);
    
    // stage 저장
    for (int i = 0; i < stages.size(); i++) {
        if (stages[i] > N) continue;
        tmp[stages[i] - 1].first++;
        tmp[stages[i] - 1].second = stages[i];
    }
    
    // 남은 부분 채워줌
    for (int i = 0; i < N; i++) { 
        if (tmp[i].second == 0) tmp[i].second = i + 1;
    }
    
    int size = stages.size();
    for (int i = 0; i < N; i++) {
        if (tmp[i].first != 0) {
            int nums = tmp[i].first;
            tmp[i].first = (double)tmp[i].first / size;
            size -= nums;
        }
    }
    
    sort(tmp.begin(), tmp.end(), cmp);
    for (int j = 0; j < tmp.size(); j++) {
        answer.push_back(tmp[j].second);
    }
    
    return answer; // 실패율이 높은 스테이지부터 저장
}