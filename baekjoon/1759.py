import sys
from string import ascii_lowercase
from itertools import combinations

L, C = map(int, sys.stdin.readline().split())
input = list(map(str, sys.stdin.readline().split()))

con = ['a', 'e', 'i', 'o', 'u']

li1 = []
li2 = []
res = set()

for i in input :
    if i not in con :
        li2.append(i)
    else :
        li1.append(i)

for i in range(2, L) :
    nl1 = list(combinations(li2, i))
    nl2 = list(combinations(li1, L - i))

    for ele1 in nl1 : 
        for ele2 in nl2 :
            nl3 = ''.join(sorted(ele1 + ele2))
            res.add(nl3)
            
for s in sorted(res) :
    print(s)
    