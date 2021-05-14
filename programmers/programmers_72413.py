



def solution(n, s, a, b, fares):
    answer = 0

    # 인접 행렬
    m = [[0 for i in range(n + 1)] for j in range(n + 1)]

    # 노드가 가지고 있는 값들
    val = [0 for i in range(n + 1)]
    for i in range(n + 1):
        val[i] = 999999999
    val[s] = 0

    # 인접 리스트
    v = [0 for i in range(n + 1)]

    # 인접 행렬 및 리스트 초기화
    for y in fares:
        m[y[0]][y[1]] = y[2]
        v[y[0]].append([y[1], y[2]])
        v[y[1]].append([y[0], y[2]])


    queue = [[s, []]]
    while queue.count() > 0 :

        node = queue[0][0]
        path = queue[0][1]
        queue.remove(0)

        for e in v[node]:
            if(val[node] + e[1] < val[e[0]]):
                



 

    return answer

