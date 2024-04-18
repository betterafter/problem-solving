N, K = list(map(int, input().split(' ')))
li = list(map(int, input().split(' ')))

def rotate(belt, N):
    temp = [0 for _ in range(2 * N + 1)]
    for b in range(1, 2 * N):
        temp[b + 1] = belt(b)
    temp[1] = belt[2 * N]

    return temp

# [로봇이 있는지 여부, 언제 올라갔는지]
belt = [[0, 0] for _ in range(2 * N + 1)]
nbelt = [[0, 0] for _ in range(2 * N + 1)]
strength = [0 for _ in range(2 * N + 1)]

for idx in range(1, len(li) + 1):
    strength[idx] = li[idx - 1]

print(strength)

cnt = 0
robots = []
while strength.count(0) - 1 < K:
    print(strength.count(0))
    # 1. 일단 벨트 회전부터
    for idx in range(1, 2 * N):
        nbelt[idx + 1] = belt[idx][:]
        print('nbelt idx:: N', idx, N, nbelt[idx])
        # N번째 위치면 내리기
        if idx == N - 1 and nbelt[idx][0] == 1:
            print('helo')
        #     nbelt[idx][0] = 0
        #     nbelt[idx][1] = 0
    nbelt[1] = belt[2 * N] 

    print('(1) ----->', nbelt)

    # 2. 로봇 옮기기
    for idx in range(1, 2 * N + 1):
        if nbelt[idx][0] == 1:
            # nbelt 정보랑 현재 위치
            robots.append([nbelt[idx][:], idx])

        robots.sort(key = lambda x: (x[1]))

    
    lastOrder = 0
    if len(robots) != 0:
        lastOrder = robots[-1][1]

    for robot in robots:
        pos = robot[1]
        # 맨 마지막일 때에는 1번으로 가야됨
        if pos == 2 * N:
            # 1번에 로봇이 없고 내구도가 1 이상이면
            if nbelt[1][0] == 0 and strength[1] >= 1:
                # 로봇을 세우고 pos의 넘버링을 채우고, 내구도 1 깎기
                nbelt[1] = [1, nbelt[pos][1]]
                strength[1] -= 1
                # 현재 위치는 로봇 없애기
                nbelt[pos] = [0, 0]

        # 다음 위치가 내리는 위치    
        elif pos == N - 1 and nbelt[pos + 1] == 1:
            nbelt[pos][0] = 0
            nbelt[pos][1] = 0 

        else:
            if nbelt[pos + 1][0] == 0 and strength[pos + 1] >= 1:
                nbelt[pos + 1] = [1, nbelt[pos][1]]
                strength[pos + 1] -= 1
                nbelt[pos] = [0, 0]

    # 1번에 로봇 올리기 시도하기
    if nbelt[1][0] == 0 and strength[1] >= 1:
        nbelt[1][0] = 1
        nbelt[1][1] = lastOrder
        strength[1] -= 1

    print(nbelt)
    belt = nbelt[:]
    print('belt::', belt)
    cnt += 1

    if (cnt >= 10):
        break


print(belt)