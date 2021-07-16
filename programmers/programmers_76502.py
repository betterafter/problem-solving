
def check(s):
    stack = []
    k = ['}', ']', ')']
    d = {'}':'{', ']':'[', ')':'(' }

    for ele in s:
        if ele in k:
            if stack and stack[-1] == d[ele]:
                #print('pop', ele, stack[-1])
                stack.pop()
                
            else:
                stack.append(ele)
        else : stack.append(ele)

    if stack : return False
    else : return True

# [](){}
# ](){}[

def ro(s):
    res = []
    for i in range(1, len(s)):
        res.append(s[i])
    res.append(s[0])

    return res


def solution(s):
    answer = 0
    ss = list(s)
    if check(ss) : answer += 1
    ss = ro(ss)

    while ''.join(ss) != s:
        if check(ss) : answer += 1
        ss = ro(ss)



    return answer