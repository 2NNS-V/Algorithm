#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = -1;
    string tmp;
    for (auto c: s) {
        if (!tmp.empty() && tmp.back() == c) tmp.pop_back();
        else tmp.push_back(c);
    }
    
    if (tmp.empty()) answer = 1;
    else answer = 0;

    return answer;
}