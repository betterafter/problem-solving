caseList = ['a', 'e', 'i', 'o', 'u']

def case2Checker(case2Str, caseList):
    if (case2Str[0] in caseList and case2Str[1] in caseList and case2Str[2] in caseList):
         return False
    elif (case2Str[0] not in caseList and case2Str[1] not in caseList and case2Str[2] not in caseList):
        return False

    return True    

def case3Checker(case3Str, caseList):
    if (''.join(case3Str) != 'ee' and ''.join(case3Str) != 'oo' and case3Str[0] == case3Str[1]):
        return False
    return True

while (True):
    pw = list(input())
    acceptMsg = '<{}> is acceptable.'
    denyMsg = '<{}> is not acceptable.'

    case1Check = False
    case2Check = True
    case3Check = True

    case2Str = []
    case3Str = []

    if (''.join(pw) == 'end'):
        break

    for c in pw:
        if (c in caseList):
            case1Check = True

        case2Str.append(c)
        if (len(case2Str) == 3):
            if (not case2Checker(case2Str, caseList)):
                case2Check = False
                case2Str.pop(0)
                break

            case2Str.pop(0)

        case3Str.append(c)
        if (len(case3Str) == 2):
            if (not case3Checker(case3Str, caseList)):
                case3Check = False
                case3Str.pop(0)
                break
                
            case3Str.pop(0)

    if (case1Check and case2Check and case3Check):
        print(acceptMsg.format(''.join(pw)))
    else:
        print(denyMsg.format(''.join(pw)))
