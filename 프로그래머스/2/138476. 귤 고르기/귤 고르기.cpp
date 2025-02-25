#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());
    
    unordered_map<int, int> m;
    for (int i = 0; i < tangerine.size(); i++) {
        m[tangerine[i]]++;
    }
    
    vector<int> v;
    for (auto elem: m) {
        // cout << elem.first << " " << elem.second << endl;
        v.push_back(elem.second);
    }
    
    sort(v.begin(), v.end());
    // for (int i = v.size() - 1; i >= 0; i--) {
    //     cout << v[i];
    // }
    
    int j = v.size() - 1;
    while (k > 0) {
        cout << v[j] << endl;
        k -= v[j--];
        answer++;
    }
    return answer;
}