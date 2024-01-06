import sys
input = sys.stdin.readline

zero = [1,0,1]
one = [0,1,1]

def fib(n):
    for i in range(len(zero), n+1):
        zero.append(zero[i-1]+zero[i-2])
        one.append(one[i-1]+one[i-2])
    return zero[n], one[n]

t = int(input())

for i in range(t):
    m = int(input())
    a, b =fib(m)
    print(a, b)

