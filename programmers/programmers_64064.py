from itertools import combinations, permutations


def solution(user_id, banned_id):
    answer = 0
    s = set()

    for ele in permutations(user_id, len(banned_id)):
        used = []
        for bid in banned_id:
            for uid in ele:
                if uid in used: continue
                match = True
                for i in range(len(bid)):
                    if len(bid) != len(uid) or (bid[i] != uid[i] and bid[i] != '*') : 
                        match = False
                        break
                if match == True:
                    used.append(uid)
                    break

        if len(used) == len(banned_id):
            used.sort()
            s.add(tuple(used))
    answer = len(s)

    return answer