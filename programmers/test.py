
# bool : 1
# short : 2
# int : 4
# long : 4
# double : 8

#       #.######
#       bool bool short short
#       bool bool int short
#       bool . . . long


def padding(buffer):
    nbuffer = []
    # 다음 원소가 마지막인데 아직 다 안 찼으면 .으로 채움

    # bool이고 다음 것도 bool이면 ##, 아니면 #.



def solution():

    ans = [[1,2,3], [2,4,6], [4,5,7],[2,4,7],[1,3,6],[4,5,6],[4,5,8],[1,2,4],[1,3,3],[2,5,6],[3,4,6]]
    ans.sort(key=lambda x : (x[0], x[1], x[2]))
    print(ans)


solution()