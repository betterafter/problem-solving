# 자주 나오는 단어일수록 앞에 배치한다.
# 해당 단어의 길이가 길수록 앞에 배치한다.
# 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다

import sys
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
words = {}

for _ in range(N):
    word = input().rstrip()
    if (len(word) < M):
        continue

    words[word] = 1 if word not in words else words[word] + 1 

words = sorted(words.items(), key = lambda x : (-x[1], -len(x[0]), x[0]))

for word in words:
    print(word[0])
