#include <string>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    int min = INT_MAX, max = INT_MIN;
    stringstream ss(s);
    string token;
    
    while (ss >> token) {
        int num = stoi(token);
        if (num < min) min = num;
        if (num > max) max = num;
    }
    
    answer += to_string(min) + " " + to_string(max);
    
    return answer;
}