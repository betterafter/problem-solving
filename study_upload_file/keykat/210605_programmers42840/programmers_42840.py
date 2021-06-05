
p1 = [1, 2, 3, 4, 5]
p2 = [2, 1, 2, 3, 2, 4, 2, 5]
p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]



def solution(answers):
    answer = []

    ans1 = 0
    ans2 = 0
    ans3 = 0

    for i in range(len(answers)):
        if(answers[i] == p1[i % 5]):
            ans1 += 1
        if(answers[i] == p2[i % 8]):
            ans2 += 1
        if(answers[i] == p3[i % 10]):
            ans3 += 1

    m = [ans1, ans2, ans3]

    if(ans1 == max(m)):
        answer.append(1)

    if(ans2 == max(m)):
        answer.append(2)

    if(ans3 == max(m)):
        answer.append(3)

    answer.sort()
    return answer


solution([1,2,3,4,5])