import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
 
dx = [-1,1,0,0,1,1,-1,-1]
dy = [0,0,-1,1,1,-1,1,-1]

def dfs(x,y):
    graph[x][y] = False

    # 8방면을 검사해서 주변에 1이 있는지 확인해야 함
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < h and 0 <= ny < w:
            if graph[nx][ny] == True:
                dfs(nx, ny)


while 1 :
    w, h = map(int, input().split())    
    if w == 0 and h ==0: break

    # 그래프 정의
    graph = [list(map(int, input().split())) for _ in range(h)] 
    cnt = 0

    for i in range(h):
        for j in range(w):
            if graph[i][j] == True :
                dfs(i, j)
                cnt += 1
    print(cnt)