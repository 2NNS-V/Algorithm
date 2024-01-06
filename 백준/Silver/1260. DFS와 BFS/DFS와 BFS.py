import sys
from collections import deque
input = sys.stdin.readline

n, m, v = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)

def dfs(x):
    visited[x] = True
    print(x, end=' ')
    
    for i in graph[x]:
        if not visited[i]:
            dfs(i)
    
def bfs(x):
    queue = deque([x])
    visited[x]=True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        
        for i in graph[v]:
            if not visited[i]:
                visited[i] = True
                queue.append(i)
    
    
for _ in range(m):
    a, b= map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()
    
    
dfs(v)
print()

visited = [False] * (n+1)
bfs(v)
