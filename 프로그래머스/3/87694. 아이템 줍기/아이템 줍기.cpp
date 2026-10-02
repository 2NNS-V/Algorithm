#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<int>> visited(102, vector<int>(102, 0));

int edge(int x, int y, vector<vector<int>> rectangle) {
    bool isEdge = false;
    
    // 테두리 여부
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0], y1 = rectangle[i][1];
        int x2 = rectangle[i][2], y2 = rectangle[i][3];
        
        if (((x1 == x || x2 == x) && (y1 <= y && y2 >= y)) || 
             ((x1 <= x && x2 >= x) && (y1 == y || y2 == y))) 
            isEdge = true;
    }
    
    if (!isEdge) return 0;
    
    for (int i = 0; i < rectangle.size(); i++) {
        if ((rectangle[i][0] < x && rectangle[i][2] > x && rectangle[i][1] < y && rectangle[i][3] > y)) return 0;
    }
    return 1;
}

int bfs(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    queue<pair<pair<int, int>, int>> q; // (x,y),n
    q.push({{characterX, characterY}, 0});
    
    int x, y, n;
    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        n = q.front().second;
        q.pop();
        visited[x][y] = 1;
        
        if (x == itemX && y == itemY) return n;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx > 0 && ny > 0 && nx <= 101 && ny <= 101) {
                if (edge(nx, ny, rectangle) && !visited[nx][ny]) {
                    q.push({{nx, ny}, n + 1});    
                    visited[nx][ny] = 1;
                }
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (int i = 0; i < rectangle.size(); i++) {
        rectangle[i][0] *= 2;
        rectangle[i][1] *= 2;
        rectangle[i][2] *= 2;
        rectangle[i][3] *= 2;
    }

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    
    return bfs(rectangle, characterX, characterY, itemX, itemY) / 2;
}