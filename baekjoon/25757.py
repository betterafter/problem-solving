N, game = input().split(' ')

glist = { 'Y': 1, 'F': 2, 'O': 3 }
users = {}
result = 0

for i in range(int(N)):
    user = input()
    # key가 있는 지 알기 위해선 dict[key] == None이 아니다.
    # 아래처럼 not in / in 으로 찾기
    if (user not in users):
        users[user] = 1
    else:
        users[user] = users[user] + 1

cnt = 0
for key in users:
    cnt = cnt + 1
    if (cnt == glist[game]):
        result = result + 1
        cnt = 0
# key만 뽑을 땐: 
#   for key in users:
# value도 뽑을 땐:
#   for key, value in users.items():

print(result)

