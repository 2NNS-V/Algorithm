#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <utility>

using namespace std;

int diff(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) cnt++;
        if (cnt > 1) return 1;
    }
    return 0;
}


int bfs(string begin, string target, vector<string> words) {
    queue<pair<string,int >> q;
    vector<int> visited(words.size(), 0);
    q.push({begin, 0});
    
    string str; int n;
    
    while (!q.empty()) {
        str = q.front().first;
        n = q.front().second;
        q.pop();
        
        if (str == target) return n;
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] != str && !diff(words[i], str) && !visited[i]) {
                q.push({words[i], n + 1});
                visited[i] = 1;
            }
        }
    }
    
    if (q.empty() && str != target) return 0;
    
}

int solution(string begin, string target, vector<string> words) {
    return bfs(begin, target, words);
}