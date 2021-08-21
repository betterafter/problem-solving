


def solution(cacheSize, cities):
    answer = 0

    cache = []
    for city in cities:
        city = city.lower()
        # 캐시에 저장되어 있으면:
        if city in cache:
            answer += 1
            # 저장되어있는거를 맨 앞으로 보내준다.
            cache.remove(city)
            cache.insert(0, city)

        # 캐시에 저장되어 있지 않다면:
        else:
            answer += 5
            # 맨 앞에 저장한다.
            cache.insert(0, city)
            # 이 때 사이즈 초과면 오래된 맨 뒤의 것을 빼준다.
            if len(cache) > cacheSize:
                cache.pop()



    return answer