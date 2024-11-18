#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
int n, m;
int ans = INT_MAX;

vector<int> visited(13, 0);
vector<pair<int, int> > home; // * 집
vector<pair<int, int> > chicken; // * 치킨집
vector<pair<int, int> > picked;

void bfs() {
    int tmp = 0, sum = 0;
    for (int j = 0; j < home.size(); j++) {
        int x = home[j].first;
        int y = home[j].second;
    
        int dist = INT_MAX;
        for(int i = 0; i < picked.size(); i++) {
                int dist_x = picked[i].first;
                int dist_y = picked[i].second;
                dist = min(dist, abs(dist_x - x) + abs(dist_y - y));
        }
        sum += dist;
        if (sum >= ans) return;
    }   
    ans = min(ans, sum);
}

void search(int idx, int cnt) {
    if (cnt == m) { // * 최대 m개 설정
        bfs();
        return;
    }

    for (int i = idx; i < chicken.size(); i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            picked.push_back(chicken[i]);  
            search(i + 1, cnt + 1);
            visited[i] = 0;
            picked.pop_back(); 
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            int num; cin >> num;
            if (num == 1) home.push_back(make_pair(i, j));
            else if (num == 2) chicken.push_back(make_pair(i, j));
        }
    }

    search(0, 0);
    cout << ans << "\n";
    return 0;
}