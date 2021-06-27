def solution(record):
    answer = []

    d = dict()

    for r in record:
        re = r.split()

        order = re[0]
        id = re[1]

        if order == 'Leave': continue
        name = re[2]
        if order == 'Enter':
            d[id] = name

        elif order == 'Change':
            d[id] = name


    for r in record:
        re = r.split()
        
        order = re[0]
        id = re[1]

        if order == 'Enter':
            answer.append('{0}님이 들어왔습니다.'.format(d[id]))
        
        elif order == 'Leave':
            answer.append('{0}님이 나갔습니다.'.format(d[id]))

    
  


    
    return answer