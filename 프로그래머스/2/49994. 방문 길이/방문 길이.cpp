#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int reverseDir(int d) { return (d + 2) % 4; }

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
    int dir = 0;
    int visited[11][11][4] = {0,};
    
    for (auto d: dirs) {
        switch (d) {
            case 'L': 
                dir = 0;
                break;
            case 'U':
                dir = 1;
                break;
            case 'R':
                dir = 2;
                break;
            case 'D':
                dir = 3;
                break;
        }
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;
        if (!visited[x][y][dir] && !visited[nx][ny][reverseDir(dir)]) {
            answer++;
        }
        visited[x][y][dir] = 1;
        visited[nx][ny][reverseDir(dir)] = 1;
        
        x = nx; y = ny;
    }
    return answer;
}