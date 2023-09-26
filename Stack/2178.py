import sys
input = sys.stdin.readline

n, m = map(int, input().split())

arr = []
arr = list(map(int, input().split()) for i in range(n)) 
print(arr)