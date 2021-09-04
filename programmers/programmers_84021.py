def rotate(game_board):
    board = [[0 for i in range(len(game_board))] for j in range(len(game_board))]
    for y in range(len(game_board)):
        for x in range(len(game_board)):
            board[y][x] = game_board[x][len(game_board) - 1 - y]
    return board
    

def check(game_board, piece):
    dir = [[0,1],[0,-1],[1,0],[-1,0]]
    visit = [[0 for i in range(100)] for j in range(100)]
    for y in range(len(game_board)):
        for x in range(len(game_board)):
            if game_board[y][x] == 0 and visit[y][x] == 0:
                # 빈 여백 모양 만들어보기
                blank = [(x,y)]
                q = [(x,y)]
                visit[y][x] = 1
                while len(q) != 0:
                    xy = q.pop(); xx = xy[0]; yy = xy[1]
                    for d in dir:
                        xxx = xx + d[1]; yyy = yy + d[0]
                        if yyy >= 0 and yyy < len(game_board) and xxx >= 0 and xxx < len(game_board):
                            if game_board[yyy][xxx] == 0 and visit[yyy][xxx] == 0:
                                visit[yyy][xxx] = 1
                                q.append((xxx, yyy))
                                blank.append((xxx, yyy))
                
                if len(blank) == len(piece):
                    s = set()
                    for idx in range(len(blank)):
                        xxxx = sorted(blank)[idx][0] - sorted(piece)[idx][0]
                        yyyy = sorted(blank)[idx][1] - sorted(piece)[idx][1]
                        s.add((xxxx,yyyy))
                    
                    if len(s) == 1:
                        for b in blank:
                            game_board[b[1]][b[0]] = 1
                        return game_board

    return game_board

def count(game_board):
    count = 0
    for ele in game_board:
        count += ele.count(0)
    return count


def solution(game_board, table):
    answer = count(game_board)
    visit = [[0 for i in range(100)] for j in range(100)]
    dir = [[0,1],[0,-1],[1,0],[-1,0]]

    for y in range(len(table)):
        for x in range(len(table)):
            
            # 조각이 있는 위치
            if table[y][x] == 1 and visit[y][x] == 0:
                piece = [(x,y)]
                q = [(x,y)]
                visit[y][x] = 1
                while len(q) != 0:
                    xy = q.pop(); xx = xy[0]; yy = xy[1]
                    for d in dir:
                        xxx = xx + d[1]; yyy = yy + d[0]
                        if yyy >= 0 and yyy < len(table) and xxx >= 0 and xxx < len(table):
                            if table[yyy][xxx] == 1 and visit[yyy][xxx] == 0:
                                visit[yyy][xxx] = 1
                                q.append((xxx, yyy))
                                piece.append((xxx, yyy))
                # 조각을 다 만들었으면 테이블 회전하면서 체크
                for i in range(4):
                    game_board = rotate(game_board)
                    c = count(game_board)
                    game_board = check(game_board, piece)
                    if count(game_board) != c: break

                # print(game_board)
                # print('\n')

    return answer - count(game_board)