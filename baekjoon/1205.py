N, new, P = list(map(int, input().split(' ')))
if (N == 0):
    print(1)
else:
    li = list(map(int, input().split(' ')))

    result = []
    if (len(li) >= P and li[P - 1] >= new):
        print(-1)
    else:
        for i, x in enumerate(li):
            if (x > new):
                result.append(x)
            elif (x == new and (len(result) == 0 or (len(result) > 0 and result[-1] != new))):
                result.append(x)
            elif (x < new):
                break

        if (len(result) == 0 or (len(result) > 0 and result[-1] != new)):
            result.append(new)

        print(len(result))