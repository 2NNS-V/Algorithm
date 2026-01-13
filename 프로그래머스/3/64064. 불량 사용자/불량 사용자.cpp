#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool isSame(string banned, string user) {
    if (banned.length() != user.length())
        return false;
    
    for (int i = 0; i < user.length(); i++) {
        if (banned[i] != '*' && user[i] != banned[i]) {
            return false;
        }
    }
    return true;
}

void dfs(vector<string> &user_id, vector<string> &banned_id, vector<int> &visited, set<set<string> > &result, set<string> &curr, int idx) {
    
    for (int i = 0; i < user_id.size(); i++) {
        if (idx == banned_id.size()) {
            result.insert(curr);
            return;
        }
        
        if (!visited[i] && isSame(banned_id[idx], user_id[i])) {
            curr.insert(user_id[i]);
            visited[i] = 1;
            dfs(user_id, banned_id, visited, result, curr, idx + 1);
            curr.erase(user_id[i]);
            visited[i] = 0;
        }
        
    }    
}

int solution(vector<string> user_id, vector<string> banned_id) {
    set<string> curr; // 조건에 맞는 user_id
    set<set<string>> result;
    vector<int> visited((int)user_id.size(), 0); // banned_id에 해당하는 user_id 방문 표시
    
    dfs(user_id, banned_id, visited, result, curr, 0);
        
    return result.size();
}