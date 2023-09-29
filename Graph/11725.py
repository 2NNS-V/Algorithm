import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n+1)]

for i in range(n - 1):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

visited = [0] * (n +1) 
def dfs(x):
    for i in graph[x]:
        if visited[i] == 0:
            visited[i] = x
            dfs(i)

dfs(1)

for j in range(2, n +1):
    print(visited[j])