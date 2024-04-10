N, X = list(map(int, input().split(' ')))
li = list(map(int, input().split(' ')))

mx = 0
result = 0
m = {}
for l in range(X):
    mx += li[l]
m[mx] = 1
result = mx

for idx in range(1, len(li) - X + 1):
    mx -= li[idx - 1]
    mx += li[idx + X - 1]
    
    m[mx] = m[mx] + 1 if mx in m else 1
    result = max(mx, result)

if (result == 0):
    print('SAD')
else:
    print(result)
    print(m[result])