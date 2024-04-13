N, M = list(map(int, input().split(' ')))

li = []
# visited[y][x][dir] -> y좌표, x좌표, 이전에 어디 방향에서 들어왔는지
visited = [[[1000000 for k in range(3)] for j in range(M)] for i in range(N)]
q = []

for n in range(N):
    li.append(list(map(int, input().split(' '))))

# x 좌표, y좌표, 방향
for n in range(M):
    visited[0][n][0] = li[0][n]
    visited[0][n][1] = li[0][n]
    visited[0][n][2] = li[0][n]

# 연속으로 같은 방향은 못 가니까 만든 맵
dirMap = {0: [1, 2], 1: [0, 2], 2: [0, 1]}

# 이렇게 해야 이전 방향에서 들어온 값 중에 가장 작은거를 찾을 수 있음
# 이전 방향을 기준으로 작은걸 찾아야지, 안 그러고 그냥 작은걸 찾아버리면 다른 방향에서 시작한게
# 당장은 더 클 수 있어도 이어지다 보면 그게 결국 정답일 수 도 있어서 무작정 작은것만 찾으면 안됨
def calc(x, y, dir, visited):
    for d in dirMap[dir]:
        nx = x + d - 1
        ny = y + 1

        if (nx >= 0 and nx < M and ny >= 0 and ny < N):
            visited[ny][nx][d] = min(visited[y][x][dir] + li[ny][nx], visited[ny][nx][d])
            
for y in range(N):
    for x in range(M):
        for dir in range(3):
            calc(x, y, dir, visited)

result = 1000000
for v in visited[N - 1]:
    result = min(result, min(v))

print(result)
