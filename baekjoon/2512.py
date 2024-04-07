# 4
# 120 110 140 150
# 485

def calc(li, mid):
    result = 0
    for i in li:
        if (i < mid):
            result += i
        else:
            result += mid

    return result

N = int(input())
li = list(map(int, input().split()))
total = int(input())

if (sum(li) < total):
    print(max(li))
else:
    start = 0
    end = max(li)
    mid = 0
    mx = 0
    while (True):
        if (start + end) // 2 == mid:
            break

        mid = (start + end) // 2

        if (calc(li, mid) < total):
            mx = mid
            start = mid + 1

        elif (calc(li, mid) > total):
            end = mid - 1

        else:
            break

    print(mid)