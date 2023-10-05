import sys
from collections import deque
input = sys.stdin.readline

m, n = map(int, input().split())

graph = deque([])

for i in range(n):
    graph.append(list(map(int, input().split())))
print(graph)

visited = [[False] * (m+1) for _ in range(n+1)]

def bfs(x, y):
    queue=deque((x,y))
    visited[x][y] = True

    while queue:
        v,w = queue.popleft()
        for i in graph[v][w]:
            if not visited[v][w]:
                queue.append((v,w))
                visited[v][w]=True