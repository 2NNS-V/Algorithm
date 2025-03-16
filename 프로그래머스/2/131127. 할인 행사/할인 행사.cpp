#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> m;
    int sum = 0;
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i];
    }
    
    for (int i = 0; i <= discount.size() - 10; i++) {
        map<string, int> tmp;
        for (int j = i; j < i + 10; j++) {
            tmp[discount[j]]++;
        }
        
        bool check = true;
        for (auto it: m) {
            if (tmp[it.first] != it.second || tmp.find(it.first) == tmp.end()) {
                check = false;
                break;
            }
        }
        
        if (check) answer++; 
    }
    return answer;
}