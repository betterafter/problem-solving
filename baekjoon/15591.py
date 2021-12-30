import sys

max = 1000000000
N, Q = map(int, sys.stdin.readline().split())
usado = []
ques = []
li = [[max for i in range(N + 1)] for j in range(N + 1)]
nli = [[] for i in range(N + 1)]

for i in range(N - 1) :
    input = list(map(int, sys.stdin.readline().split()))
    li[input[0]][input[1]] = input[2]
    li[input[1]][input[0]] = input[2]
    nli[input[1]].append(input[0])
    nli[input[0]].append(input[1])
    
for i in range(Q) :
    ques.append(list(map(int, sys.stdin.readline().split())))
            
for q in ques :
    k = q[0]
    p = q[1]
    cnt = 0
    visited = [0 for i in range(N + 1)]
    visited[p] = 1
    q = [p]
    while len(q) != 0 :
        data = q.pop(0)
        for r in nli[data] :
            if visited[r] == 0 :
                visited[r] = 1
                q.append(r)
                li[p][r] = min(li[p][data], min(li[p][r], li[data][r]))       
                if p != r and li[p][r] >= k : cnt += 1
    print(cnt)
