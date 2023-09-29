import sys
input = sys.stdin.readline

# 전체 사람 수
n = int(input())

# 촌수를 계산해야 하는 두 사람의 번호
a, b = map(int, input().split())

# 부모 자식들 간의 관계 개수
m = int(input())

graph = [[] for _ in range(n+1)]
result = []

# 부모 자식간의 관계를 나타내는 번호(x는 y의 부모)
for i in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

visited = [False] * (n+1)
cnt = 0

def dfs(x):
    global cnt
    cnt += 1

    visited[x] = True

    if x == b: result.append(cnt)
    for i in graph[x]:
        if not visited[i]:
            dfs(i)

dfs(a)

if len(result) == 0: print(-1)
else: print(result[0]-1)