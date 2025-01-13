#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(int i, int j) {
    return j < i;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());

    unordered_map<int, int> arr;
    for (int i = 0; i < tangerine.size(); i++) {
        arr[tangerine[i]]++;
    }
    
    vector<int> v;
    for (auto &i:arr) {
        v.push_back(i.second);
    }
    sort(v.begin(), v.end(), compare);

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (sum >= k) break;
        answer++;
        sum += v[i];
    }
    return answer;
}