# TODO: 3차원 배열로 해결해보자

N, M = list(map(int, input().split(' ')))

li = []
visited = [[1000000000 for j in range(M)] for i in range(N)]
q = []

for n in range(N):
    li.append(list(map(int, input().split(' '))))

# x 좌표, y좌표, 방향
for n in range(M):
    q.append([n, 0, -1])
    q.append([n, 0, 0])
    q.append([n, 0, 1])

    visited[0][n] = li[0][n]

while (len(q) != 0):
    pos = q.pop()
    x = pos[0]
    y = pos[1]
    dir = pos[2]

    for d in range(-1, 2):
        if (d == dir):
            continue

        nx = x + d
        ny = y + 1

        if (nx >= 0 and nx < M and ny >= 0 and ny < N):
            nValue = visited[y][x] + li[ny][nx]
            if (nValue <= visited[ny][nx]):
                visited[ny][nx] = nValue
                q.append([nx, ny, d])

                # print('x, y, dir: ', x, y, dir, ' ::: ', visited[y][x], li[ny][nx], '  ->  ', 'nx, ny, d:', nx, ny, d, '  ::: ', visited[ny][nx])

print(visited)
print(min(visited[N - 1]))
