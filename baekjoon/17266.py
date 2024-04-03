import math

N = int(input())
M = int(input())
lights = list(map(int, input().split()))

least = lights[0]
least = max(least, N - lights[-1])
result = 0

# least보단 크고 반띵 중에서 가장 큰 것
for idx, light in enumerate(lights):
    if (idx + 1 < len(lights)):
        result = max(least, max(result, math.ceil((lights[idx + 1] - light) / 2)))

result = max(least, result)
print(result)
