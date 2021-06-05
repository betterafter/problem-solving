import math

i = list(map(int, input().split()))

print(i)


#m = [[0 for j in range(2 ** i[0])] for jj in range(2 ** i[0])]
size = int(2 ** i[0])
m = [
    [0 for j in range(size + 2)]
        for jj in range(size + 2)
]

# for ii in range(2 ** i[0]):
#     mm = []
#     for iii in range(2 ** i[0]):
#         mm.append(0)
#     m.append(mm)



def div(len, x, y, num):
    if len == 2:   
 
        x = int(x)
        y = int(y)

        m[y][x] = int(num - 3)
        m[y][x + 1] = int(num - 2)
        m[y + 1][x] = int(num - 1)
        m[y + 1][x + 1] = int(num)


    else:
        div(len // 2, x - len // 2, y - len // 2, num - ((len // 2) ** 2) * 3)
        div(len // 2, x, y - len // 2, num - ((len // 2) ** 2) * 2)
        div(len // 2, x - len // 2, y, num - ((len // 2) ** 2) * 1)
        div(len // 2, x, y, num)


div(size, size, size, size * size - 1)

#print(m)

# for y in m:
#     print(y)
#     print('\n')

print(m[i[1] + 2][i[0] + 2])