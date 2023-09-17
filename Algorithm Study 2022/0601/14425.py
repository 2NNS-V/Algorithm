import sys

n, m=map(int, sys.stdin.readline().split())
cnt=0
a = {sys.stdin.readline().strip() for i in range(n)}

for i in range(m):
    c = sys.stdin.readline().strip()
    if c in a:
        cnt+=1
print(cnt)

    
