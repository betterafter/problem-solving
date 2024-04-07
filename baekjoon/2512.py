# 4
# 120 110 140 150
# 485

N = int(input())
li = list(map(int, input().split()))
total = int(input())
target = total // N

cnt = 0
curr = target * 4
for i in li: 
    if (i > target):
        cnt += 1
    else:
        curr -= i

print(curr / cnt)
