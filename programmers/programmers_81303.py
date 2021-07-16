def solution(n, k, cmd):
  
    answer = ''
    stack = []

    for c in cmd : 

        if c[0] == 'U' :
            cnt = int(c[2:])
            k -= cnt

        elif c[0] == 'D' :
            cnt = int(c[2:])
            k += cnt

        elif c[0] == 'C' : 
            stack.append(k)
            n -= 1
            if k == n : k -= 1

        elif c[0] == 'Z' :
            ele = stack[-1]
            del stack[-1]
            if k >= ele : k += 1
            n += 1

    for i in range(n):
        answer += 'O'

    while stack : 
        s = stack[-1]
        del stack[-1]
        answer = answer[:s] + 'X' + answer[s:]
    
    return answer
