//
//  kakao2020_4.cpp
//  Contest
//
//  Created by 신기열 on 04/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 이 문제는 trie 자료구조를 사용해야 효율성 테스트를 통과할 수 있다. 물론 다른 방법도 있지만 일단 나는 trie만으로 풀었다.
// trie는 짧게 말하자면 사전처럼 a 다음에 a~z까지 가지들을 만들고, 다시 그 다음 문자들도 똑같이 a~z 까지의 가지를 만들어 전부 탐색하는 방식이다. 물론 문제에
// 따라 당연히 다 만들 필요는 없고, 현재 문자열이 이 트리에 포함되어 있으면 그냥 반환만 해주고, 트리에 포함 안되어있으면 포함 된 문자열 다음에 가지를 새로 만들어
// 주는 방법이다.
// ex)
//  |-- p -- p -- l -- e
//  a ---- d -- d
//              |-- r -- e -- s -- s
// 처럼 apple, add, address 라는 문자열이 담긴 트리에 app을 찾으려면 당연히 apple에서 찾을 수 있으니 그냥 반환해주고, adder라는 문자열을 찾고 싶으면
//  |-- p -- p -- l -- e
//  a ---- d -- d -- e -- r
//              |-- r -- e -- s -- s
// 처럼 그냥 추가만 해주면 되는 것이다. 나중에 따로 정리하도록 하겠다.


// trie를 이루는 노드. 각 노드는 다음 문자들에 대한 맵 정보를 담고 있다.
struct trieNode{
    
    char ch;
    int count;
    trieNode *parentnode;
    map<char, trieNode*> child;
    trieNode(char ch) : ch(ch){}
    
};

class trie{
    
    // trie 트리는 root 노드를 가지고 시작한다. root노드는 자식이 아무것도 없으며, 아무런 데이터도 가지고 있지 않은 노드이다.
    public :
    trieNode *rootnode;
    //int length;
    trie() : rootnode(new trieNode('\0')){};
    
    // 트리에 문자열을 삽입하는 과정
    void Tinsert(string word){
        
        trieNode *currnode = rootnode;

        int i = 0;
        // 삽입하고자 하는 문자열과 트리를 대조해준다.
        while(i < word.size()){
            // 트리의 현재 노드의 자식 중에 문자열의 다음 탐색 문자가 존재하지 않으면 반복문을 탈출한다.
            // 가령 application에서 app까진 있는데 l이 없으면 탈출
            // count 는 각 노드의 위치에서 모든 가지가 몇개인지 카운트 해주는 것인데, 문제에서 가사의 단어는 중복되는 단어는 제외하므로 무조건적으로 다른
            // 문자열이 올 것이기 때문에 그냥 문자열이 추가되면 가지가 새롭게 추가된다고 봐도 된다.
            if(currnode -> child.count(word[i]) == 0) break;
            // 있으면 현재 탐색 노드를 다음 노드로 옮긴다. p -> l로 옮기는 과정
            else{
                currnode -> count++;
                currnode = currnode -> child[word[i]];
            }
            i++;
        }

        // 탈출한 인덱스부터 다시 탐색해준다.
        while(i < word.size()){
            // 현재 노드의 자식 맵에 문자열의 문자를 삽입하고, 삽입한 자식노드로 위치를 옮긴다.
            // p 다음에 l을 삽입하고, currnode = l node 로 위치를 옮기는 과정
            currnode -> child.insert(make_pair(word[i], new trieNode(word[i])));
            currnode -> count++;
            currnode = currnode -> child[word[i]];
            i++;
        }
        
        // 맨 마지막 노드는 당연히 가지가 없이 자기 자신밖에 없으므로 count = 1이다.
        i = 0;
        currnode -> count = 1;

    }

    // 문자열이 존재하는지 체크하기 위한 함수
    int Tsearch(string word){
        trieNode *currnode = rootnode;
        // 더 간단하다. 찾는 문자열을 돌면서 자식 맵에 다음 문자가 존재하는 지 체크하고, 존재하면 다음 노드로 이동한다.
        for(int i = 0; i < word.size(); i++){
            if(currnode -> child.count(word[i]) != 0){
                currnode = currnode -> child[word[i]];
            }
            // 체크 도중에 맵에 다음 문자가 없으면 그냥 0을 return 해준다. 문제 기준으로 어떤 트리에도 'pro??' 에서 pro 가 포함된 트리가 없으므로
            // 개수도 0이 된다.
            else return 0;
        }
        // 문제 기준으로 'fro??' 는 frodo, front, frost에 포함되므로 3개이고, 'fr???'는 frodo, front, frost, frame에 포함되므로 4개이다.
        // 즉 fr에서 r 노드는 4개의 count를, fro에서 o 노드는 3개의 count를 가지고 있는 것이다.
        return currnode -> count;
    }
    
};


vector<int> solution(vector<string> words, vector<string> queries) {

    vector<int> answer;

    // 문제에서 문자열의 길이는 1 ~ 10000까지 다양하다. 문자열 길이까지 trie에서 체크해주려면 복잡해지니까 그냥 길이가 고정된 trie를 여러개 만들어서 특정
    // 길이에 해당되는 trie에 문자열을 넣어서 돌려주게 만들었다.
    trie Trie[10001];
    trie reTrie[10001];

    for(int i = 0; i < words.size(); i++){
        // 문자열은 앞에서부터 ???... 가 나오는 경우와 뒷부분이 ...??? 인 경우 2가지가 존재한다. 즉 ?가 중간부터 시작되는 경우는 없다. 따라서
        // trie를 역trie도 하나 만들어서 삽입해주면 편하다.
        // 입력하는 word를 trie에 삽입해 돌리고, reverse해줘서 역trie에 삽입해서 돌려주는 과정을 한번씩 해준다.
        Trie[words[i].size()].Tinsert(words[i]);
        reverse(words[i].begin(), words[i].end());
        reTrie[words[i].size()].Tinsert(words[i]);
    }

    for(int i = 0; i < queries.size(); i++){
        // answer는 벡터이므로 그냥 할당하기 위한 과정
        answer.push_back(0);
        string tmp;
        // queries의 첫부분이 '?'가 나오면 역trie에 넣어줘야한다.
        if(queries[i][0] == '?'){
            int j = (int)(queries[i].size() - 1);
            //'?' 가 아닌 지점부터 문자열을 새롭게 만들어준다. 즉 '?'를 제거하는 과정이라고 봐도 된다.
            while(queries[i][j] != '?'){
                tmp = tmp + queries[i][j];
                j--;
            }
            // 만들어진 문자열을 역trie에 넣고 돌린다.
            answer[i] = reTrie[queries[i].size()].Tsearch(tmp);
            
        }
        // queries의 마지막부분이 '?'인 경우. 역시 똑같이 하면 된다.
        else{
            int j = 0;
            while(queries[i][j] != '?'){
                tmp += queries[i][j];
                j++;
            }
            answer[i] = Trie[queries[i].size()].Tsearch(tmp);
        }
    }

    
    return answer;
}

// 느린 방법
//vector<int> solution(vector<string> words, vector<string> queries) {
//
//    vector<int> answer;
//    int qsize = (int)queries.size();
//    int wsize = (int)words.size();
//
//
//    for(int i = 0; i < qsize; i++){
//
//        answer.push_back(0);
//
//        for(int j = 0; j < wsize; j++){
//
//            int flag = 0;
//            if(queries[i].size() == words[j].size()){
//                for(int k = 0; k < queries[i].size(); k++){
//
//                    if(queries[i][k] != '?'){
//                        if(queries[i][k] != words[j][k]){
//                            flag = 1;
//                            break;
//                        }
//                    }
//                }
//
//                if(flag == 0) answer[i]++;
//                flag = 0;
//            }
//        }
//    }
//
//
//    return answer;
//}

int main(){
    
    vector<string> testword, testqueries;

    testword.push_back("frodo");
    testword.push_back("front");
    testword.push_back("frost");
    testword.push_back("frozen");
    testword.push_back("frame");
    testword.push_back("kakao");

    testqueries.push_back("fro??");
    testqueries.push_back("????o");
    testqueries.push_back("fr???");
    testqueries.push_back("fro???");
    testqueries.push_back("pro?");

    //solution(testword, testqueries);
    
    for(int i = 0; i < solution(testword, testqueries).size(); i++){
        cout << solution(testword, testqueries)[i] << '\n';
    }
    



    
    return 0;
}
