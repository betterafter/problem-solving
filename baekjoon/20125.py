N = int(input())
li = []

def inRange(arr):
    x = arr[0] 
    y = arr[1]
    if (x >= 0 and x < N and y >=0 and y < N):
        return True
    else:
        return False

def calcLeftArm(leftArm, li, result):
    x = leftArm[0]
    y = leftArm[1]
    cnt = 0
    while (inRange([x, y]) and li[y][x] == '*'):
        cnt += 1
        x = x - 1
    
    result.append(cnt)

def calcRightArm(rightArm, li, result):
    x = rightArm[0]
    y = rightArm[1]
    cnt = 0
    while (inRange([x, y]) and li[y][x] == '*'):
        cnt += 1
        x = x + 1
    
    result.append(cnt)

def calcWaist(waist, li, result):
    x = waist[0]
    y = waist[1]
    cnt = 0
    while (inRange([x, y]) and li[y][x] == '*'):
        cnt += 1
        y = y + 1
    
    result.append(cnt)
    leftLeg = [x - 1, y]
    rightLeg = [x + 1, y]
    calcLeg(leftLeg, li, result)
    calcLeg(rightLeg, li, result)

def calcLeg(leftLeg, li, result):
    x = leftLeg[0]
    y = leftLeg[1]
    cnt = 0
    while (inRange([x, y]) and li[y][x] == '*'):
        cnt += 1
        y = y + 1
    
    result.append(cnt)

for i in range(N):
    li.append(list(input()))

dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
heartPos = []
result = []

for y in range(N):
    for x in range(N):

        heart = True
        for d in dir:
            nx = x + d[0]
            ny = y + d[1]

            if (inRange([nx, ny]) and li[ny][nx] == '*'):
                heart = True
            else:
                heart = False
                break

        if (heart):
            heartPos = [y + 1, x + 1]
            result.append(heartPos)
            
            leftArm = [x - 1, y]
            rightArm = [x + 1, y]
            waist = [x, y + 1]

            calcLeftArm(leftArm, li, result)
            calcRightArm(rightArm, li, result)
            calcWaist(waist, li, result)

print('{} {}'.format(result[0][0], result[0][1]))
print('{} {} {} {} {}'.format(result[1], result[2], result[3], result[4], result[5]))
