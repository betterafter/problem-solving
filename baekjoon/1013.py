import sys
import re

n = int(input())

for i in range(n) :
    case = input()
    reg = re.compile('(100+1+|01)+')
    if reg.fullmatch(case) :
        print("YES")
    else :
        print("NO")
    
        