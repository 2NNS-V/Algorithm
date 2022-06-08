import sys

n=int(sys.stdin.readline())
index=set(sys.stdin.readline().rstrip())
m=int(sys.stdin.readline())
s=set(sys.stdin.readline().rstrip())

for i in range(m):
    if s in index:
        print(1)
    else :
        print(0)
