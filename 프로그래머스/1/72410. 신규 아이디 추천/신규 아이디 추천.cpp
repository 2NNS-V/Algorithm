#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

// 아이디 길이 : 3 ~ 15
// 소문자, 숫자, -, _, . 만 사용 가능
// . 은 처음과 끝만 가능
string solution(string new_id) {
    string answer = "";
    
    // 대문자를 소문자로 변경
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] += 32;
        }
    }
    
    // 소문자, 숫자, -, _, . 빼고 지우기
    string new_str;
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'a' && new_id[i] <= 'z') {
            new_str += new_id[i];
        }
        else if (new_id[i] == '_' || new_id[i] == '-' || new_id[i] == '.') {
            new_str += new_id[i];
            
        }
        else if (new_id[i] >= '0' && new_id[i] <= '9') {
            new_str += new_id[i];
        }
    }
    new_id = new_str;
    while (!new_str.empty()) {
        new_str.pop_back();
    }
    
    int k = 0, p = 0;
    while (p < new_id.size()) {
        if (new_id[k] == '.') {
            while (1) {
                if (new_id[k] != '.') break;
                k++;
            }
            new_str += new_id[k-1];
            p = k;
        }
        else {
            k++;
            new_str += new_id[p++];
        }
    }
    
    new_id = new_str;
    while (!new_str.empty()) {
        new_str.pop_back();
    }
    
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.' && (i == 0 || i == new_id.size() - 1)) continue;
        new_str += new_id[i];
    }
    if (new_str.empty()) new_str += 'a';
    int size = new_str.size();
    if (new_str.size() >= 16) {
        for (int i = 16; i <= size; i++) {
            new_str.pop_back();
        }
    }
    
    if (new_str[new_str.size() - 1] == '.') new_str.pop_back();
    if (new_str.size() <= 2) {
        char ch = new_str[new_str.size() - 1];
        cout << ch;
        while (new_str.size() != 3) {
            cout << new_str.size() << endl;
            new_str.push_back(ch);
        }
    }
    answer = new_str;
    
    return answer;
}