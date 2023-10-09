import sys
input = sys.stdin.readline

n, m = map(int, input().split())

arr = []
for j in range(1,n+1):
    arr.append(j)
print(arr)

# 총 반복 횟수
result = 1
for i in range(m):
    result *= n
    n = n-1

def dfs(i):
    

for k in range(result):
    for i in range(len(arr)-1):
        for j in range(len(arr)-2):
            if arr[j] == arr[i]:
                j = j + 1
            print(arr[i], arr[j])