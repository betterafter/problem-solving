

def check(nplaces):
    for i in range(2, 7):
        for j in range(2, 7):
            if nplaces[i][j] == 'P':

                if nplaces[i][j + 1] == 'P': return False
                if nplaces[i][j - 1] == 'P': return False
                if nplaces[i + 1][j] == 'P': return False
                if nplaces[i - 1][j] == 'P': return False

                if nplaces[i][j + 2] == 'P' and (nplaces[i][j + 1] == 'O' or nplaces[i][j + 1] == 'P'): return False
                if nplaces[i][j - 2] == 'P' and (nplaces[i][j - 1] == 'O' or nplaces[i][j - 1] == 'P'): return False
                if nplaces[i + 2][j] == 'P' and (nplaces[i + 1][j] == 'O' or nplaces[i + 1][j] == 'P'): return False
                if nplaces[i - 2][j] == 'P' and (nplaces[i - 1][j] == 'O' or nplaces[i - 1][j] == 'P'): return False
                
                if nplaces[i + 1][j + 1] == 'P':
                    if nplaces[i][j + 1] == 'O' or nplaces[i][j + 1] == 'P': return False
                    if nplaces[i + 1][j] == 'O' or nplaces[i + 1][j] == 'P': return False

                if nplaces[i + 1][j - 1] == 'P':
                    if nplaces[i][j - 1] == 'O' or nplaces[i][j - 1] == 'P': return False
                    if nplaces[i + 1][j] == 'O' or nplaces[i + 1][j] == 'P': return False

                if nplaces[i - 1][j + 1] == 'P':
                    if nplaces[i][j + 1] == 'O' or nplaces[i][j + 1] == 'P': return False
                    if nplaces[i - 1][j] == 'O' or nplaces[i - 1][j] == 'P': return False

                if nplaces[i - 1][j - 1] == 'P':
                    if nplaces[i][j - 1] == 'O' or nplaces[i][j - 1] == 'P': return False
                    if nplaces[i - 1][j] == 'O' or nplaces[i - 1][j] == 'P': return False
    return True
        



def solution(places):
    answer = []
    
    for p in places:
        nplaces = []
        nplaces.append('XXXXXXXXX')
        nplaces.append('XXXXXXXXX')

        for pp in p:
            nplaces.append('XX' + pp + 'XX')

        nplaces.append('XXXXXXXXX')
        nplaces.append('XXXXXXXXX')

        if check(nplaces) == True: answer.append(1)
        else: answer.append(0)

    return answer