res = 0
n = []

def dfs(nums, numbers, i, target):
    if len(nums) == len(numbers):
        # print(nums)
        count = 0
        for i in nums:
            count += i
        if count == target:
            global res 
            res += 1
        return
    
    nums.append(numbers[i])
    dfs(nums, numbers, i + 1, target)
    nums.pop()
    
    nums.append(-numbers[i])
    dfs(nums, numbers, i + 1, target)
    nums.pop()
    
            

def solution(numbers, target):
    answer = 0
    nums = []
    dfs(nums, numbers, 0, target)
    
    global res
    answer = res
    return answer