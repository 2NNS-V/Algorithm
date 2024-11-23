#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    
    // 소문자로 바꾸어 줌
    for (string& city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
    }
    
    // 캐시에 존재하면 1
    // 캐시에 존재하지 않으면 5
    for (const string& city : cities) {
        auto it = find(cache.begin(), cache.end(), city);
        if (it != cache.end()) { // cache hit
            answer += 1;
            cache.erase(it);
            cache.push_back(city);
        } else { // cache miss
            answer += 5;
            if (cache.size() == cacheSize && cacheSize > 0) {
                cache.pop_front();
            }
            if (cacheSize > 0) {
                cache.push_back(city);
            }
        }
    }
    return answer;
}