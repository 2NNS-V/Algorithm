import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

dp = [1 for _ in range(n)]

for i in range(len(arr)):
    for j in range(i):
        if arr[j] > arr[i]:
            dp[i] = max(dp[j] + 1, dp[i])
print(max(dp))