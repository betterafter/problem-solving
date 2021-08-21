import re
from string import ascii_lowercase

def solution():

    #b = re.compile("[^a-z]muzi[^a-z]")
    #print(b.findall("0muzi0muzi0muzi !muzimuzi! "))

    word = "muzi"
    page = "0muzi0muzi0muzi !muzimuzi! "
    basic = []
    alpha_list = list(ascii_lowercase)
    i = page.find(word)
    print(len(word))
    while(i >= 0):
        if page[i - 1] not in alpha_list and page[i + len(word)] not in alpha_list:
            basic.append(word)
        page = page[i + len(word):]
        i = page.find(word)
        
        #print(idx)


    print(basic)

solution()