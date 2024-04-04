from queue import PriorityQueue

# 자주 나오는 단어일수록 앞에 배치한다.
# 해당 단어의 길이가 길수록 앞에 배치한다.
# 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다

frequencies = {}

class Word:
    def __init__(self, frequency, length, dictSort):
        self.frequency = frequency
        self.length = length
        self.distSort = dictSort
    
    def __it__(self, other):
        frequencies.clear()
        if (self.frequency != other.frequency):
            return self.frequency > other.frequency
        elif (self.length != other.length):
            return self.length > other.length
        else:
            return [self, other].sort().first

N, M = list(map(int, input().split(' ')))

que = PriorityQueue()
frequencies = {}

print(frequencies)
# 전체 단어 체크
for i in range(N):
    frequencies[i] = 1 if i not in frequencies else frequencies[i] + 1 

for i in range(N):
    word = input()
    if (len(word) < M):
        continue

    que.put(Word(frequencies[i], word, word))


while not que.empty():
    print(que.get())
