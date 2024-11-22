#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<string> year, month, day; 
   
    // today 분리
    int todayYear, todayMonth, todayDay;
    sscanf(today.c_str(), "%d.%d.%d", &todayYear, &todayMonth, &todayDay);
    
    unordered_map<char, int> termDuration;
    for (const string& term : terms) {
        char type;
        int duration;
        stringstream ss(term);
        ss >> type >> duration;
        termDuration[type] = duration * 28; 
    }
 
    
    // privacies 분리
   for (int i = 0; i < privacies.size(); i++) {
        string date, type;
        stringstream ss(privacies[i]);
        ss >> date >> type;

        int year, month, day;
        sscanf(date.c_str(), "%d.%d.%d", &year, &month, &day);

        int totalDays = year * 12 * 28 + month * 28 + day + termDuration[type[0]];
        int todayTotalDays = todayYear * 12 * 28 + todayMonth * 28 + todayDay;

        if (totalDays <= todayTotalDays) {
            answer.push_back(i + 1); 
        }
    }
        

    return answer;
}