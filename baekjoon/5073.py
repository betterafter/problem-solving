typeList = ['Equilateral', 'Isosceles', 'Scalene', 'Invalid']

while (True) :
    li = list(map(int, input().split(' ')))
    li.sort()
    
    if (li == [0, 0, 0]):
        break
    
    if (li[2] >= li[0] + li[1]):
        print(typeList[3])
    
    elif (li[0] == li[1] and li[0] == li[2]):
        print(typeList[0])
    
    elif (li[0] == li[1] or li[1] == li[2] or li[0] == li[2]):
        print(typeList[1])
    
    elif (li[0] != li[1] and li[0] != li[2] and li[1] != li[2]):
        print(typeList[2])