#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

map<string, int> dur; // 주차 누적 시간 계산


int calc(string in, string out) {
//     int duration = 0;
    
//     int one = out[4] - in[4];
//     int ten; 
//     if (one < 0) out[3] - 1 - in[3];
//     else ten = out[3] - in[3];
    
//     duration = abs(one) + 10 * abs(ten);
    
//     if (ten < 0) one = out[1] - 1 - in[1];
//     else one = out[1] - in[1];
    
//     if (one < 0) ten = out[0] - 1 - in[0];
//     else ten = out[0] - in[0];
    
//     duration += abs(ten) * 600 + abs(one) * 60;
    
    return (600  * (out[0] - in[0]) + 60 * (out[1] - in[1]) + 10 * (out[3] - in[3]) + (out[4] - in[4]));
}

void accu(int duration, string num) {
    // 차량 번호가 dur에 있으면 기존 시간 + 새 시간
    auto it = dur.find(num);
    if (it != dur.end()) {
        it->second += duration;
    }
    // 차량 번호가 dur에 없으면 새 시간으로 업데이트
    else {
        dur.insert({num, duration});
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> timetable;
    map<string, int> fair;
    
    for (auto i : records) {
        stringstream ss(i);
        string in, num, state;
        ss >> in >> num >> state;
        
        if (state == "IN") { // IN인 경우 timetable에 추가(차 넘버, 시각)
            timetable.insert({num, in});
        }
        
        else { // OUT인 경우 timetable에서 num으로 찾아보기 -> 시간 계산
            string out = in;
            for (auto iter = timetable.begin() ; iter != timetable.end(); iter++) {
                if (iter->first == num) {
                    in = iter->second;
                    timetable.erase(iter);
                    break;
                }
            }
            
            accu(calc(in, out), num);
        }
    }
    
    // TODO: out이 없는데 timetable이 남아있는 경우 체크해야 함
    if (!timetable.empty()) {
        for (auto i: timetable) {
            string in = i.second;
            string out = "23:59";
            accu(calc(in, out), i.first);
        }
    }
    
    // 차량 번호 별 최종 요금 계산
    for (auto j : dur) {
        int fee = 0, duration = j.second;
        cout << duration << endl; 
        fee = fees[1]; 
        
        if (duration > fees[0]) {
            int extra = duration - fees[0];
            int units = (extra + fees[2] - 1) / fees[2]; 
            fee += units * fees[3];
        }
        fair.insert({j.first, fee});
    }
    
    
    for (auto i : fair) {
        answer.push_back(i.second);
    }
    return answer;
}