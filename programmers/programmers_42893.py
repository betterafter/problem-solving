import re
from string import ascii_lowercase

def solution(word, pages):
    word = word.lower()
    answer = 0
    # 이렇게 찾지말고 org:url content=... 형식을 아예 찾아서 group으로 묶고 group 넘버링으로 찾으면 더 간편하게 찾을듯. 링크도 마찬가지.
    meta = re.compile("<meta(.+?)/>")
    link = re.compile("<a(.+?)>")

    m = dict()

    for page in pages:

        score = []
    
        # 해당 페이지의 링크 구하기
        currLink = meta.search(page).group()
        sidx = currLink.find("content=") + 9
        eidx = currLink.rfind("\"")
        url = currLink[sidx:eidx]

        basic = []
        # 기본 점수 구하기
        # 생각해보니까 muzi라는 것을 찾는다고 할 때, 어떤 정규표현식으로 찾기가 매우 까다로움
        # 0muzi0muzi0muzi muzi... 이런 게 있다고 한다면
        # 정규표현식으로 찾으려고 해도 0muzi0은 하나의 단어 취급도 하기 때문에 구분도 안되고 그렇다고 "[^a-z]*" + word + "[^a-z]*"
        # 와 같은 표현식으로 찾으려고 하면 0muzi0이 먹어버리니까 다음 muzi는 못찾음. 결국 하나씩 다 끊어서 찾아봐야됨
        # 아래의 경우는 알파벳 대소문자로만 이루어진 모든 단어들을 뒤져서 찾는 방법
        basicScore = 0
        for f in re.findall('[a-zA-Z]+', page.lower()):
            if f == word.lower():
                basic.append(f)
        
        score.append(basic)
        print(basic)

        #print(basic)
        
        # 외부 링크 수 구하기
        outerLink = link.findall(page)
        links = []

        for l in outerLink:
            l = l.replace(' ', '')
            l = l.replace('href=', '')
            l = l.replace('\"', '')
            links.append(l)
            
        score.append(links)
        if len(links) == 0: score.append(0)
        else: score.append(len(basic) / len(links))
        score.append(0)

        m[url] = score


    # 링크 점수 갱신하기
    for mm in m:
        for child in m[mm][1]:
            if child in m:
                m[child][3] += m[mm][2]
             

    res = []
    # 매칭 점수 갱신하기
    for mm in m:
        res.append(len(m[mm][0]) + m[mm][3])
        
        
    score = 0
    idx = 0
    for i in range(len(res)):
        if score < res[i]:
            score = res[i]
            idx = i

    return idx