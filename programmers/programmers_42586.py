def solution(progresses, speeds):
    answer = []
    queue = []
    for idx in range(len(progresses)):
        if (100 - progresses[idx]) % speeds[idx] != 0:
            queue.append(int((100 - progresses[idx]) / speeds[idx]) + 1)
        else:
            queue.append(int((100 - progresses[idx]) / speeds[idx]))
    #print(queue)
    temp = 99999999999999999
    while len(queue) != 0:
        count = 1
        curr = queue[0]
        del queue[0]
        while len(queue) != 0 and curr >= queue[0]:
            count+=1
            del queue[0]
        answer.append(count)
        
    
    return answer