



def check(m, n):

    for y in range(n + 1):
        for x in range(n + 1):

            # 기둥일 때
            if m[y][x][0] == 1 : 
                if y != 0 and m[y][x - 1][1] == 0 and m[y][x][1] == 0 and m[y - 1][x][0] == 0:
                    return False
            # 보일 때
            if m[y][x][1] == 1 :
                if (m[y][x - 1][1] == 0 or m[y][x + 1][1] == 0) and m[y - 1][x][0] == 0 and m[y - 1][x + 1][0] == 0:
                    return False

    return True

    



def solution(n, build_frame):
    answer = []
    m = [[[0 for i in range(2)] for j in range(n + 1)] for k in range(n + 1)]

    for i in range(len(build_frame)):

        x = build_frame[i][0]
        y = build_frame[i][1]
        t = build_frame[i][2]
        bt = build_frame[i][3]

        # 삭제할 경우
        if bt == 0:
             # 기둥
            if t == 0:
                m[y][x][0] = 0
                if check(m, n) == False:
                    m[y][x][0] = 1

            # 보
            elif t == 1:
                m[y][x][1] = 0
                if check(m, n) == False:
                    m[y][x][1] = 1
           

        # 설치할 경우
        elif bt == 1:
             # 기둥
            if t == 0:
                m[y][x][0] = 1
                if check(m, n) == False:
                    m[y][x][0] = 0
            # 보
            elif t == 1:
                m[y][x][1] = 1
                if check(m, n) == False:
                    m[y][x][1] = 0


    for y in range(n + 1):
        for x in range(n + 1):
            if m[y][x][0] == 1 : answer.append([x, y, 0])
            if m[y][x][1] == 1 : answer.append([x, y, 1])

    
    answer.sort(key=lambda x : (x[0], x[1], x[2]))


    return answer


