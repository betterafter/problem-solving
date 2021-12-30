from itertools import combinations

a = int(input())

li = []
for i in range(1, 11):
    for j in combinations(range(0, 10), i):
        l = list(reversed(list(j)))
        li.append(int(''.join(map(str, l))))
li.sort()
        
if a >= len(li): print(-1)
else : print(li[a])