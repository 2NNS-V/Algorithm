#include <string>
#include <vector>

using namespace std;
int visited[201]={0,};

void dfs(int x, int n, vector<vector<int>> computers);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0;i<n;i++) {
        if (visited[i] == 0) {
            dfs(i, n, computers);
            answer++;
        } 
    }
    return answer;
}

void dfs(int x, int n, vector<vector<int>> computers) {
    visited[x] =  1;
    
    for (int i=0;i<n;i++) {        
        if (visited[i]== 0 && computers[x][i] == 1) {
                dfs(i, n, computers);
        }
    }
}