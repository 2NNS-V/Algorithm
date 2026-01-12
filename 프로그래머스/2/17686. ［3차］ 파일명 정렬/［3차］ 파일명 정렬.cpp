#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

pair<int, int> divide(string s) {
    int start = 0, i = 0, len = 0;
    int check = 0;
    while (i < s.length()) {
        if (check && !(s[i] >= '0' && s[i] <= '9')) break;
        
        bool isDigit = (s[i] >= '0' && s[i] <= '9');
        bool prevIsDigit = (i > 0) && (s[i - 1] >= '0' && s[i - 1] <= '9');
        
        if (isDigit && !prevIsDigit) {
            start = i;
            len = 1;
            check = 1;
        }
        else if (isDigit && prevIsDigit) {
            len++;
        }
        i++;
    }
    return {start, len};
}

string getHead(string s) {
    pair<int, int> tmp = divide(s);
    string head = s.substr(0, tmp.first);
    for (int i = 0; i < head.length(); i++) {
        if (islower(head[i])) head[i] = toupper(head[i]);
    }
    return head;
}

int getNumber(string s) {
    pair<int, int> tmp = divide(s);
    string number = s.substr(tmp.first, tmp.second);
    return stoi(number);
}


bool numberSort(string s1, string s2) {
    return getNumber(s1) < getNumber(s2);
}

bool headSort(string s1, string s2) {
    return getHead(s1).compare(getHead(s2)) < 0;
}


vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), numberSort);
    stable_sort(files.begin(), files.end(), headSort);
    
    return files;
}