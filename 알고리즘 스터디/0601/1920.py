n=int(input())
index=set(map(int, input().split()))
m=int(input())
s=list(map(int, input().split()))

for i in s:
    if i in index:
        print(1)
    else :
        print(0)
