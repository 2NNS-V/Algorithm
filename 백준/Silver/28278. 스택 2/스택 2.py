from collections import deque
import sys

stack = deque()
n = int(input())

for i in range(n):
    input = sys.stdin.readline().strip()

    if len(input) > 2:
        stack.append(int(input[2:]))
    elif (input == '2'):
        if stack: print(stack.pop())
        else: print(-1)
    elif (input == '3'):
        print(len(stack))
    elif (input == '4'):
        if stack: print(0)
        else: print(1)
    elif (input == '5'):
        if stack: print(stack[-1])
        else: print(-1)