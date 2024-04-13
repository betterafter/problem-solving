N, K = list(map(int, input().split(' ')))
table = list(input())
visited = [False for _ in range(N)]

cnt = 0
for idx, type in enumerate(table):
    if (type == 'P'):
        for ii in range(idx - K, idx + K + 1):
            if (ii >= 0 and ii < len(table)):
                if (table[ii] == 'H' and not visited[ii]):
                    # print(idx, ' can eat at ', ii)
                    visited[ii] = True
                    cnt += 1
                    break

print(cnt)
                 