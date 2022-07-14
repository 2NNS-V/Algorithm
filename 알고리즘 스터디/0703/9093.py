import sys
t = int(sys.stdin.readline())
stack=[]

for _ in range(t) :
    word = sys.stdin.readline().split()
    for j in word:
        stack.extend(j)
        while stack:
            print(stack.pop(), end='')
        print(end=' ')
            




