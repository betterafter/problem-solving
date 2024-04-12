li = list(input())

# 1 10 11 1(2) 1(3) 1(4) 

index = 0
curr = 1

if (li[index] == '1'):
    index += 1

while (index < len(li)):
    next = curr + 1
    while (True):
        if (li[index] in str(next)):
            break
        next += 1
    
    nextStr = str(next)
    # print('next: ', next, 'index: ', index)
    for c in nextStr:
        if (index < len(li) and li[index] == c):
            index += 1

    curr = next
    # print(index, curr)

print(curr)



        