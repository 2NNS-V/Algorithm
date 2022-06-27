n = input()
arr=list(map(int, input().split()))

def DynamicProgramming(arr):
    cache = [None] * len(arr)
    cache[0] = arr[0]
    for i in range(1, len(arr)):
        cache[i] = max(0, cache[i-1]) + arr[i] 
    return max(cache)


print(DynamicProgramming(arr))