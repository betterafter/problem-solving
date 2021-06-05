



def solution(n, lost, reserve):
    answer = 0

    count = []
    for i in range(n + 2):
        count.append(0)

    for i in lost:
        count[i] += -1

    for i in reserve:
        count[i] += 1

    for i in range(len(count)):
        if(count[i] > 0):
            if(count[i - 1] == -1):
                count[i] -= 1
                count[i - 1] += 1
            elif(count[i + 1] == -1):
                count[i] -= 1
                count[i + 1] += 1

    count = count[1:len(count) - 1]

    for i in count:
        if i == 0 or i == 1:
            answer += 1

    return answer

#print(solution(5, [2,4], [1,3,5]))