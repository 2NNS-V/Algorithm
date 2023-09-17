n=input()
k=input()

nums = str(list(range(1, n+1)))
idx = k-1
answer=[]
while True:
    answer.append(nums[idx])
    nums=nums[:idx]+nums[idx+1]
    if not nums:
        break
    idx = (idx+k-1)%len(nums)

print('<' + ','.join(list(map(str, answer))) + '>')