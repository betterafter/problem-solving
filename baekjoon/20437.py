import math

T = int(input())

for t in range(T):
    W = input()
    K = int(input())

    m = {
        'a': 0, 'b': 0, 'c': 0, 'd': 0, 'e': 0, 'f': 0, 'g': 0,
        'h': 0, 'i': 0, 'j': 0, 'k': 0, 'l': 0, 'm': 0, 'n': 0,
        'o': 0, 'p': 0, 'q': 0, 'r': 0, 's': 0, 't': 0, 'u': 0,
        'v': 0, 'w': 0, 'x': 0, 'y': 0, 'z': 0
    }


    answer3 = 10000000
    answer4 = 0

    left = 0
    right = 1
    currW = W[left:right]
    m[currW[left]] = 1
    while left < len(W) and right < len(W):
        # 3번 구하기
        if K in m.values():
            answer3 = min(answer3, right - left)
            if currW[0] == currW[-1]:
                print(currW)
                answer4 = max(answer4, len(currW))
            if left < len(W) - 1:
                m[W[left]] -= 1
                left += 1
        else:
            if right < len(W) - 1:
                right += 1
                m[W[right - 1]] += 1
            else:
                m[W[left]] -= 1
                left += 1
            
        currW = W[left:right]

    left = 0
    right = 1
    while left < len(W) and right < len(W):
        # 3번 구하기
        print(left, right - 1, W[left], W[right - 1])
        if K in m.values():
            if currW[0] == currW[-1]:
                print(currW)
                answer4 = max(answer4, len(currW))
                if right < len(W) - 1:
                    right += 1
                    m[W[right - 1]] += 1
            else:
                if left < len(W) - 1:
                    m[W[left]] -= 1 
                    left += 1
        else:
            if right < len(W) - 1:
                right += 1
                m[W[right - 1]] += 1
            else:
                m[W[left]] -= 1
                left += 1
            
        currW = W[left:right]

    print(answer3, answer4)