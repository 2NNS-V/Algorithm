import sys
input = sys.stdin.readline

n = int(input())

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

arr.sort()
start = arr[0][0]
end = arr[0][1]
length = 0

for new_arr in arr:
    if new_arr[0] <= end:
        if new_arr[1] >= end:
            end = new_arr[1]
    else:
        length += (end - start)
        start = new_arr[0]
        end = new_arr[1]
length += (end - start)
print(length)