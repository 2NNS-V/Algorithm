import sys
from collections import deque
input = sys.stdin.readline

m, n =map(int, input().split())

graph = []

for i in range(n):
    graph.append(list(map(int, input().split())))
print(graph)

visited = [[False] * (m+1) for _ in range(n+1)]

def bfs(x, y):
    queue=deque()
    visited[x][y] = True

    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True