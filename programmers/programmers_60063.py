from collections import deque

def move(pos, board):
    res = []
    pos.sort(key = lambda x: (x[0],x[1]))
    x1 = pos[0][0]
    y1 = pos[0][1]
    x2 = pos[1][0]
    y2 = pos[1][1]

    dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for dx, dy in dir:
        n1 = (x1 + dx, y1 + dy)
        n2 = (x2 + dx, y2 + dy)

        if board[n1[1]][n1[0]] == 0 and board[n2[1]][n2[0]] == 0:
            res.append((n1, n2))

    if x1 == x2:
        if board[y2][x2 + 1] == 0 and board[y2 - 1][x2 + 1] == 0:
            res.append((pos[0], (x2 + 1, y2 - 1)))

        if board[y2][x2 - 1] == 0 and board[y2 - 1][x2 - 1] == 0:
            res.append((pos[0], (x2 - 1, y2 - 1)))

        if board[y1][x1 - 1] == 0 and board[y1 + 1][x1 - 1] == 0:
            res.append(((x1 - 1, y1 + 1), pos[1]))

        if board[y1][x1 + 1] == 0 and board[y1 + 1][x1 + 1] == 0:
            res.append(((x1 + 1, y1 + 1), pos[1]))

    if y1 == y2:
        if board[y1 - 1][x1] == 0 and board[y1 - 1][x1 + 1] == 0:
            res.append(((x1 + 1, y1 - 1), pos[1]))

        if board[y1 + 1][x1] == 0 and board[y1 + 1][x1 + 1] == 0:
            res.append(((x1 + 1, y1 + 1), pos[1]))
        
        if board[y2 - 1][x2] == 0 and board[y2 - 1][x2 - 1] == 0:
            res.append((pos[0], (x2 - 1, y2 - 1)))
        
        if board[y2 + 1][x2] == 0 and board[y2 + 1][x2 - 1] == 0:
            res.append((pos[0], (x2 - 1, y2 + 1)))

    return res

def solution(board):

    size = len(board)
    nboard = [[2 for i in range(102)] for j in range(102)]

    for i in range(size):
        for j in range(size):
            nboard[i + 1][j + 1] = board[i][j]

    board = nboard
    
    queue = deque( [ ( (1, 1), (2, 1), 0 ) ] )
    v = set([( (1, 1), (2, 1) )])



    while queue:
        n1, n2, cnt = queue.popleft()
        if n1 == (size, size) or n2 == (size, size) : 
            return cnt

        for ele in move([n1, n2], board):
            if ele not in v:
                #print(*ele, cnt + 1)
                queue.append((*ele, cnt + 1))
                v.add(ele)
