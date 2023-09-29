import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

cnt = 0
t = int(input())

dx, dy = [1,0,-1,0], [0,1,0,-1]

def dfs(x, y):
    if 0 > x or x >= m or y < 0 or y >= n:
        return False
    
    if graph[y][x] == 1:
        graph[y][x] = 0

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx,ny)
        return True
    return False

for j in range(t):
    cnt = 0
    m, n, k = map(int, input().split())
    graph = [[0] * m for i in range(n)]
    for i in range(k):
        x, y = map(int, input().split())
        graph[y][x] = 1

    for p in range(m):
        for q in range(n):
            if dfs(p, q) == True:
                cnt += 1
    print(cnt)