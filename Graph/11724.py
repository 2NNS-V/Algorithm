import sys
sys.setrecursionlimit(5000)
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]

cnt = 0

for i in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [False] * (n+1)

def dfs(x) :
    visited[x] = True
    for i in graph[x]:
        if not visited[i]:
            dfs(i)

cnt = 0 # 연결 요소 개수

for i in range(1, n+1):
    if not visited[i]:
        dfs(i)
        cnt += 1

print(cnt)