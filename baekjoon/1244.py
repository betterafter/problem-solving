# 남학생, sn = n * k -> switch
# 여학생, n == sn -> _ _ _ _ _ sn _ _ _ _ _
def boyCount(number, switches):
    for idx, switch in enumerate(switches):
        if ((idx + 1) % number == 0):
            switches[idx] = int(not switch)
    
    # print(switches)

def girlCount(number, switches):
    n = 1
    for idx, switch in enumerate(switches):
        if (idx + 1 == number):
            switches[idx] = int(not switch)
            while (idx - n >= 0 and idx + n < len(switches) 
                   and switches[idx - n] == switches[idx + n]):
                switches[idx - n] = int(not switches[idx - n])
                switches[idx + n] = int(not switches[idx + n])
                n += 1
            break

    # print(switches)
    return n

N = int(input())
switches = list(map(int, input().split(' ')))

SN = int(input())
for i in range(SN):
    student = list(map(int, input().split(' ')))
    gender = student[0]
    number = student[1]

    if (gender == 1):
        boyCount(number, switches)
    elif (gender == 2):
        girlCount(number, switches)


splitResult = [switches[i * 20 : (i + 1) * 20] for i in range((len(switches) + 20 - 1) // 20)]
for switchList in splitResult:
    print(' '.join(map(str, switchList)))