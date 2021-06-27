def solution(N, stages):
    answer = []

    li = [0 for i in range(N + 10)]
    li2 = [0 for i in range(N + 10)]
    li3 = [0 for i in range(N + 10)]
    fail = []

    for s in stages:
        li[s] += 1 
        
    for i in range(1, N + 1):
        
        for j in range(i, N + 2):
            li2[i] += li[j]

        li3[i] = li2[i] -  li[i]

    for i in range(1, N + 1):
        if li2[i] != 0:
            fail.append([i, (li2[i] - li3[i]) / li2[i]])
        else:
            fail.append([i, 0])

    fail.sort(key=lambda x:(-x[1],x[0]))

    for f in fail:
        answer.append(f[0])





    return answer