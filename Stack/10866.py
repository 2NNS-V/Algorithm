from collections import deque
import sys

n = int(sys.stdin.readline())
d = deque()

for i in range(n):
    command = sys.stdin.readline().split()

    if command[0] == 'push_front':
        d.appendleft(int(command[1]))
    elif command[0] == 'push_back':
        d.append(int(command[1]))
    elif command[0] == 'pop_front':
        if d: print(d.popleft())
        else: print(-1)
    elif command[0] == 'pop_back':
        if d: print(d.pop())
        else: print(-1)
    elif command[0] == 'size':
        print(len(d))
    elif command[0] == 'empty':
        if d: print(0)
        else: print(1)
    elif command[0] == 'front':
        if d: print(d[0])
        else: print(-1)
    elif command[0] == 'back':
        if d: print(d[-1])
        else: print(-1)

