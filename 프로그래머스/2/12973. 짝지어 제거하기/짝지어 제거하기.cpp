#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = -1;
        string tmp;
    
    for (char c : s) {
        if (!tmp.empty() && tmp.back() == c) tmp.pop_back();
        else tmp.push_back(c);
    }
    
    if (tmp.length() == 0) answer = 1;
    else answer = 0;
    
    return answer;
}