# 2208.py
import sys

input = sys.stdin.readline
n, m = map(int, input().split())

nlist = []
prefix_sum = [0]

for a in range(n):
    nlist.append(int(input()))

sum = 0
max = 0

for i in range(n):
    sum += nlist[i]
    prefix_sum.append(sum)
print(prefix_sum)

# (m-1) ~ n
for i in range(m-1, n):
    q = 0
    for j in range(i, len(prefix_sum)):
        print(prefix_sum[j] - prefix_sum[q], end=' ')