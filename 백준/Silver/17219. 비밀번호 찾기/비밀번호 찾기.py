import sys
n, m=map(int,input().split())
str={}

for i in range(n):
    u,v=sys.stdin.readline().rstrip().split()
    str[u]=v

for i in range(m):
    print(str[sys.stdin.readline().rstrip()])