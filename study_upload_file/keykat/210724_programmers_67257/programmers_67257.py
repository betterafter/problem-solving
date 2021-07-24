from itertools import permutations

# + - *, 100+200-300*400
# 1. 맨 뒤의 걸로 스플릿 --> 100+200-300, 400
# 2. 그 다음 걸로 스플릿 --> 100+200, 300(-), 400(*)
# 3. 연산 후 return --> 300, 300, 400
# 4. 재귀 --> 300-300, 400 --> 0, 400 --> 0
def calc(exp, expression):

    if exp == 1:
        return str(eval(expression))

    # +-*이면 -> * -> - -> +
    expression = expression.split(exp[-1])
    res = ''

    # 100+200-300, 400
    for e in expression:
        if '+' not in e and '-' not in e and '*' not in e:
            res = res + e + exp[-1]
        else:
            res = res + str(calc(exp[0:-1], e)) + exp[-1]
    res = res[0:-1]

    return eval(res)


def solution(expression):
    answer = []

    exp = ['+','-','*']
    exp = list(map(''.join, permutations(exp, 3)))

    for e in exp:
        answer.append(abs(calc(e, expression)))

    #print(answer)
    return max(answer)