N = int(input())
for i in range(N):
    T = int(input())
    allLi = list(map(int, input().split(' ')))
    li = []

    teams = {}
    teamsLastMember = {}
    teamsCount = {}

    for member in allLi:
        teamsCount[member] = (1 if member not in teamsCount else teamsCount[member] + 1)

    for item in allLi:
        if (teamsCount[item] >= 6):
            li.append(item)

    teamsCount = {}
    for idx, member in enumerate(li):
        index = idx + 1
        if (member not in teams):
            teams[member] = index

        else:
            if (teamsCount[member] < 4):
                teams[member] += index
            else:
                if (member not in teamsLastMember):
                    teamsLastMember[member] = index
        
        teamsCount[member] = 1 if member not in teamsCount else teamsCount[member] + 1
        

    # print(teams)
    # print(teamsLastMember)
    # print(teamsCount)

    mx = list(teams.keys())[0]
    for team in teams:
        if (teams[mx] > teams[team] or 
            (teams[mx] == teams[team] and teamsLastMember[mx] > teamsLastMember[team])):
            mx = team

    
    print(mx)
