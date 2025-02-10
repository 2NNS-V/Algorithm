#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = 0;
    // 50 50 70 80
    for (int i = people.size() - 1; i >= 0; i--) {
        if (people[i] == 0) continue;
        if (people[i] + people[left] <= limit) {
            people[left++] = 0;
        }
        answer++;
    }
    
    return answer;
}