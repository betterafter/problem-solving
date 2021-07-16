

# def solution(s):
#     answer = []

#     s = s[1:len(s) - 1].replace('{', '')
#     s = s.replace('},' , ' ')
#     s = s.replace('}', '')
#     ss = s.split(' ')

#     a = []
#     for i in ss:
#         k = list(map(int, i.split(',')))
#         a.append(k)

#     a.sort(key = len)
#     for aa in a:
#         for aaa in aa:
#             if aaa not in answer:
#                 answer.append(aaa)

#     return answer


def solution(s):
    answer = []

    s = sorted(s[2:-2].split('},{'), key = len)
    for aa in s:
        aa = list(map(int,aa.split(',')))
        for aaa in aa:
            if aaa not in answer:
                answer.append(aaa)

    return answer