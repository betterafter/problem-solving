from queue import PriorityQueue
import heapq


def solution(scoville, K):
    answer = 0

    h = []
    for s in scoville:
        heapq.heappush(h, s)

    while h:
        #print(h)
        if h[0] >= K : break
        if len(h) == 1:
            if h[0] < K : return -1

        

        f1 = heapq.heappop(h)
        f2 = heapq.heappop(h)
        
        sco = f1 + f2 * 2
        answer += 1

        heapq.heappush(h, sco)

    return answer
