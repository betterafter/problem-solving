import sys
input = sys.stdin.readline

T = int(input())

for t in range(T):
    W = input().rstrip()
    K = int(input())

    cntDict = {}
    idxDict = {}
    
    answer3 = len(W)
    answer4 = -1

    check = False

    for ch in W:
        cntDict[ch] = cntDict.get(ch, 0) + 1

    for i in range(len(W)):
        if cntDict[W[i]] >= K:
            idxDict[W[i]] = idxDict.get(W[i], []) + [i]
            check = True
        
    for keys, values in idxDict.items():
        for idx in range(len(values) - K + 1):
            answer3 = min(answer3, values[idx + K - 1] - values[idx] + 1)
            answer4 = max(answer4, values[idx + K - 1] - values[idx] + 1)

    if check:
        print(answer3, answer4)
    else:
        print(-1)