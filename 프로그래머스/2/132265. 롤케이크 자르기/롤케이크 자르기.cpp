#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> base, cmp;

int solution(vector<int> topping) {
    int answer = 0;
    
    for (auto i: topping) {
        base[i]++;
    }
    
    int cake_size = base.size();
    for (auto i: topping) {
        base[i]--; cmp[i]++;
        if (base[i] == 0) cake_size--;
        if (cake_size == cmp.size()) answer++;
    }
    
    return answer;
}