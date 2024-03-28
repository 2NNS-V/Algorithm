import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

maps = []
for _ in range(n):
    maps.append(list(map(int, input().rstrip())))

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
queue = deque()
def bfs(x, y):
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 1:
                queue.append((nx,ny))
                maps[nx][ny] = maps[x][y]+1
    return maps[n-1][m-1]
print(bfs(0,0))
