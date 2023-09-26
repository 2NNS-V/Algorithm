import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
 
dx = [-1,1,0,0,1,1,-1,-1]
dy = [0,0,-1,1,1,-1,1,-1]

def dfs(x,y):
    visited[x][y] = True

    # 그래프가 1일 때 땅으로 판단, 
    # 8방면을 검사해서 주변에 1이 있는지 확인해야 함
    if graph[x][y] == True:
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < h and 0 <= ny < w and graph[nx][ny] == True:
                    dfs(nx, ny)


while 1 :
    w, h = map(int, input().split())    
    if (w == 0 and h ==0): break

    # 그래프 정의
    graph = [] 

    # 방문 여부 체크
    visited = [[False for _ in range(w)] for _ in range(h) ] 

    cnt = 0

    for i in range(h):
        graph.append(list(map(int, input().split())))
    
    for i in range(h):
        for j in range(w):
            if graph[i][j] == True and visited[i][j] == False:
                dfs(i, j)
                cnt += 1
            else : continue
    print(cnt)