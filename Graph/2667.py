import sys
input = sys.stdin.readline
n = int(input())

cnt = 0 # 집 수
num = [] # 단지 내 집 수 저장
graph = [] # 단지
sum = 0

for _ in range(n):
    graph.append(list(map(int, input().strip())))

dx, dy = [1,0,-1,0], [0,1,0,-1]

def dfs(x ,y):
    if x < 0 or x >= n or y < 0 or y >= n:
        return False
    
    if graph[x][y] == 1:
        global cnt, comp
        graph[x][y] = 2
        cnt += 1

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx,ny)
        return True
    return False

for i in range(n):
    for j in range(n):
        if dfs(i, j) == True:
            num.append(cnt)
            cnt = 0
            sum += 1

num.sort()
print(sum)
for i in range(len(num)):
    print(num[i])