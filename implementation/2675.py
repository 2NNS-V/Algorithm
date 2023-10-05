import sys
input = sys.stdin.readline

t = int(input())

for i in range(t):
    r = input().strip()
    n = int(r[0])
    p = ""
    length = len(r[2:])
    for j in range(2, length + 2):
        p += r[j] * n
    print(p)