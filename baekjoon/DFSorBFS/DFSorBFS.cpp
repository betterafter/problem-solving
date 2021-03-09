//
//  DFSorBFS.cpp
//  test
//
//  Created by 신기열 on 31/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

list<int> Adj[1001];
bool Visited[1001];

//DFS
void DFS(int x){
    
    //x번 노드는 방문했으니까 true
    Visited[x] = true;
    cout << x << " ";
    
    list<int>::iterator iter;
    //x번의 인접리스트를 전부 돌면서 x의 자식 노드 중 방문한 적 없는 노드가 있으면 그 노드를 깊이 우선 탐색 실행 (재귀)
    for(iter = Adj[x].begin(); iter != Adj[x].end(); iter++){
        if(!Visited[*iter]) DFS(*iter);
    }
}

//BFS
void BFS(int x){
    
    queue<int> Search;
    
    //Visited 전부 false로 초기화
    //문제 순서가 DFS -> BFS이고 DFS에서 Visited를사용했으니 여기서 초기화해주는 것
    for(int i = 1; i <= 1000; i++){
        Visited[i] = false;
    }
    //x 방문여부
    Visited[x] = true;
    Search.push(x);
    
    //탐색해야하는 노드가 존재하지 않을 때까지는 계속 탐색해주기
    while(!Search.empty()){
        int q = Search.front();
        Search.pop();
        cout << q << " ";
        
        //Search 대상인 노드의 자식 노드 중 방문한 적이 없는 노드가 있으면 그 노드를
        //Search 대상에 포함시켜놓는 작업 반복 (Search queue에 push)
        list<int>::iterator iter;
        for(iter = Adj[q].begin(); iter != Adj[q].end(); iter++){
            
            if(!Visited[*iter]){
                
                Visited[*iter] = true;
                Search.push(*iter);
            }
        }
    }
}

int main(){
    
    int N, M, V;
    cin >> N >> M >> V;
    
    for(int i = 0; i < M; i++){
        int parent, child;
        cin >> parent >> child;
        
        //간선이 양방향임
        Adj[parent].push_back(child);
        Adj[child].push_back(parent);
    }
    
    for(int i = 1; i <= N; i++){
        
        //문제에서 정점의 번호 크기가 작은 것부터 탐색한다고 했으므로 정렬해줌.
        //참고로 vector나 배열은 sort(v.begin(), v.end()) 나 sort(a, a++) 꼴이지만
        //list의 정렬 방법은 아래와 같다.
        Adj[i].sort();
    }
    
    DFS(V);
    cout << '\n';
    BFS(V);
    cout << '\n';
    return 0;
}
