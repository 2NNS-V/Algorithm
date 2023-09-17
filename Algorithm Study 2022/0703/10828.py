import sys

n = int(sys.stin.readline())
stack = []

for _ in range(n) :
    word = sys.stdin.readline().split()

    if word[0] == "push":
        stack.append(word[1])
    elif word[0] == "pop":
        if len(stack):
            print(stack.pop())
        else : print(-1)
    elif word[0] == "size":
        if len(stack):
            print(len(stack))
    elif word[0] == "empty" :
        if len(stack):
            print(0)
        else: print(1)
    elif word[0] == "top":
        if len(stack):
            print(stack[-1])
        else: print(-1)

