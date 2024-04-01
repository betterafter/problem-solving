n = int(input())
for i in range(n):
    li = list(map(int, input().split(' ')))
    case = li.pop(0)
    rli = []
    cnt = 0
    for j in li:
        isFind = False
        curr = 0
        # print('-------------------', j, '----------------------')
        for idx, k in enumerate(reversed(rli)):
            if (k > j):
                curr = idx + 1
                isFind = True
                # print(idx, rli)
    
        if (not isFind):
            rli.append(j)
        else:
            cnt = cnt + curr
            rli.insert(len(rli) - curr, j)

    # print(rli)
    print('{} {}'.format(case, cnt))