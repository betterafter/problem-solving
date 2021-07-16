

def solution(s):
    answer = len(s)
    size = len(s)

    for i in range(1, size):
        res = ''
        curr = s[:i]
        cnt = 1
        k = i
        while k < size :
            if s[k : k + i] == curr:
                cnt += 1
            else: 
                if cnt == 1 : res = res + curr
                else : res = res + str(cnt) + curr
                curr = s[k : k + i]
                cnt = 1
            k += i

            if k >= size : 
                if cnt == 1 : res = res + curr
                else : res = res + str(cnt) + curr
                break
        
        #print(i, res)
        if len(res) < answer : answer = len(res)



    return answer