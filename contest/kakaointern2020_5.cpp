#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <queue>

// 실수했던 것 정리


// 1. 일단 이 문제에서 주의할 점은 order 쌍으로 묶여있는 방을 꼭 연속으로 찾을 필요가 없다는 점이다.
//    가령 (4,1), (2,5) 라는 order가 주어진다고 무조건 4 -> 1 을 찾은 후 2 -> 5 를 찾을 이유가 없다.
//    그냥 4, 1, 2, 5 중에 방문할 수 있는 방을 모조리 찾아다니면 된다. 대신 1번 방은 4번을 방문해야하고 5번 방은 2번 방을 방문해야할 뿐이다. 
//    즉 4번 방과 2번 방을 미리 방문해놓으면 1번 방과 5번 방은 나중에라도 방문해도 되고, 4 -> 1 -> 2 -> 5 로 방문해도 되고... 조건만 맞으면 어떻게 방문해도
//    상관 없다는 얘기. 문제를 완전히 잘못 이해해서 시간을 미친듯이 잡아먹었다. (내 논리는 맞는 것 같았는데! 문제가 잘못했네!)




// 2. 방문 조건이 붙어있는 특수한 방들을 손쉽게 찾기 위해 order에서 추출해 map에 저장해놓았었다. 위의 예를 다시 사용하면
//    map[1] = 4, map[5] = 2 와 같이 어떤 "key방"은 "value방"을 방문해야한다는 것을 빠르게 확인할 수 있게 저장해 놓았는데, 여기서 트리를 순회할 때 
//    현재 지나고 있는 방이 특수한 방인지를 찾으려면 map을 순회하던가, order를 순회해야하는데, 여기서 효율성 부분에서 시간초과가 난다. 

//    그래서 pair<종속 여부, 방문 조건이 되는 다른 방> 으로 묶어서 
//    '종속 여부' 는 1 : 먼저 방문해야하는 방   2 : 나중에 방문하는 방  으로 정하고
//    '방문 조건이 되는 다른 방' 은 방 번호로 저장하여 위의 예시를 다시 가져와서

//    opair[n] = pair<order, room>
//    opair[4] = pair<1, 1>    ... (4번은 1번보다 먼저 방문해야하는 방이므로 앞은 1이 되고 1번 방과 연결되어 있다)
//    opair[1] = pair<2, 4>    ... (1번은 4번방을 방문한 후 방문해야하는 방이므로 앞은 2가 되고 4번 방과 연결되어 있다)
//    opair[2] = pair<1, 5>    ... (2번은 5번보다 먼저 방문해야하는 방이므로 앞은 1이 되고 5번 방과 연결되어 있다)
//    opair[5] = pair<2, 2>    ... (5번은 2번방을 방문한 후 방문해야하는 방이므로 앞은 2가 되고 2번 방과 연결되어 있다)

//    이런 식으로 묶어서 opair[특정 방 번호]의 order가 2일 경우 종속된 방(room)을 방문했는지 체크를 하게 해줬다. 만약 0번 방에서 해당 방까지 쭉 갈 수 있으면
//    0번 방부터 해당 방까지 visited를 전부 true로 만들어줬다.




// 3. 0번 방이 order 안에 들어가 있는 경우 때문에 틀린 사람들도 있다고 하는데.. 본인은 그 케이스도 예외없이 짜서 잘 모르겠지만, 혹시 해당 부분을 자신이 빠트렸는지
//    확인해보도록 하자.




// 4. 주어진 양방향 트리는 앞이 부모고 뒤가 자식 노드인게 아니다. 그냥 무작위 순서다. 혹시 단방향 트리를 이용해 만든다면 이 부분을 꼭 주의하도록 하자. 진짜
//    치사하고 드럽다.





// 5. 다른 사람들의 풀이를 보면 사이클 여부로 체크한 경우도 있고, dfs, bfs를 이용해서 풀기도했고... 여러가지 방법으로 풀었는데, 본인도 변형 dfs로 
//    각 노드에 (여기서는 res 벡터에 트리 구조를 저장했다.) 해당 방의 부모를 저장하게 해서, 해당 방부터 부모를 쭉 따라서 0번까지 막힘없이 갈 수 있는지 체크하는
//    방식으로 풀었다. order에 저장되어 있는 특수 방들을 모두 deque에 집어넣고 하나씩 꺼내면서
//    1) 해당 방이 다른 방에 종속된 특수방인지? -> 종속된 방이면 우선방문방을 이미 방문했는지 체크 (방문했으면 3번으로, 방문안했으면 덱 뒤에 다시 넣기)
//    2) 해당 방이 우선 방문해야하는 특수방인지? -> 우선방문방이면 그냥 3번으로
//    3) 해당 방부터 0번방까지 부모를 따라 올라가면서 특수방을 만나 막히는지? (조상방이 종속방이면 우선방문방을 방문했는지 확인, 우선방문방이면 그냥 방문체크)
//    위의 과정을 체크하면서 답이 false인 경우는 덱에서 빼질 못해서 사이즈가 똑같을테니까 사이즈가 줄지 않는 순간 false를 출력하고, 덱을 전부 빼면 true를 출력




using namespace std;

vector<vector<int> > lawm(200010);
vector<int> res(200010);
bool visited[200010] = { false, };
pair<int, int> opair[200010];

// 현재 방에서 parent (0번 방) 까지 쭉 올라가면서 특수방에 막히지 않는지 체크해준다.
bool findRoute(int curr, int parent){
    while(curr != parent){
        //res[curr]는 curr의 부모방. curr를 res[curr]로 바꿔서 부모를 따라 0번방까지 올라가게 한다.
        curr = res[curr];
        // 만약 해당 방이 opair안에 있는 특수방이면서, 종속된 방이면서, 우선방문방은 방문하지 않은 경우 막혀있는 경우이므로 0번까지 도달할 수 없다. false 리턴
        if(opair[curr].first == 2 && !visited[opair[curr].second]) return false;
    }
    return true;
}

// 현재부터 0번까지 쭉 올라가면서 전부 방문 체크를 해주자.
void makeVisited(int curr){
    visited[curr] = true;
    while(curr != 0){
        curr = res[curr];
        visited[curr] = true;
    }
}

bool find(vector<vector<int> > order){
    
    // 덱에 order 안에 있는 모든 특수방들을 넣어주자. 이 때 2번째 인자는 종속방(1)인지, 우선방문방(2)인지 판별하는 인자를 넣자.
    deque<pair<int, int> > dq;
    for(int i = 0; i < order.size(); i++){
        dq.push_back(make_pair(order[i][0], 1));
        dq.push_back(make_pair(order[i][1], 2));
    }

    while(!dq.empty()){

        int size = dq.size();
        for(int i = 0; i < size; i++){

            int o = dq.back().second, n = dq.back().first;
            dq.pop_back();
            // 종속방이면
            if(o == 2){
                // 해당 방에 대한 우선방문방이 방문이 되었는지 확인 -> 안됐으면 덱에 다시 넣고 우선방문방이 방문되길 빌자.
                if(!visited[opair[n].second]) dq.push_front(make_pair(n, o));
                // 방문은 했으면 해당 방에서 0번방까지 쭉 따라올라가면서 어딘가에서 막히지 않았는지 확인해보자. 안막혔으면 올라가면서 만난 방 전부 방문표시.
                else if(findRoute(n, 0)) makeVisited(n);
                // 막혀버리면 덱에 다시 넣고 다음 순서엔 막히지 않길 또 빌자.
                else dq.push_front(make_pair(n, o));
            }
            // 우선방문방이면
            else if(o == 1){
                // 얘는 어차피 지가 먼저 방문해야 하는 방이므로 종속방과 같이 다른 방의 방문여부가 상관 없음.
                // 따라서 이 방부터 0번 방까지 막히지 않았는지만 체크해주면 된다.
                if(findRoute(n, 0)) makeVisited(n);
                else dq.push_front(make_pair(n, o));
            }
        }
        // 덱 한바퀴 돌았는데 사이즈가 그대로이면 영원히 안빠진다는 뜻임. 무한 사이클이니까 false 리턴.
        if(size == dq.size()) return false;
    }
    // 덱이 다 빠지면 true
    return true;
}

// 역순서 트리 구축. 해당 방에 대해 부모 방 번호를 저장하자. 
// 즉 문제 1번 예시인 [0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5] 같은 경우
// res[1] = 0, res[3] = 0, res[7] = 0, res[8] = 1 ... 같은 경우가 나오도록 하자.
// 참고로 0번 방은 문제에서 나온대로 무조건 최상위 root 노드다. 
// 코드는 어렵지 않으니 설명 생략. 
void make_tree(){

    queue<pair<int, int> > q;
    for(int i = 0; i < lawm[0].size(); i++){
        q.push(make_pair(lawm[0][i], 0));
        res[lawm[0][i]] = 0;
    }

    while(!q.empty()){
        int parent = q.front().second;
        int curr = q.front().first;
        q.pop();

        for(int i = 0; i < lawm[curr].size(); i++){
            if(lawm[curr][i] != parent){
                res[lawm[curr][i]] = curr;
                q.push(make_pair(lawm[curr][i], curr));
            }
        }
    }
}



// visited : 방 방문 체크
// opair : 위의 2번에서 설명한 것처럼 특수방인지 여부를 쉽게 체크하기 위한 pair 배열
bool solution(int n, vector<vector<int> > path, vector<vector<int> > order) {

    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    for(int i = 0; i < path.size(); i++){
        int front = path[i][0];
        int back = path[i][1];

        lawm[front].push_back(back);
        lawm[back].push_back(front);
    }

    for(int i = 0; i < order.size(); i++){
        opair[order[i][0]] = make_pair(1, order[i][1]);
        opair[order[i][1]] = make_pair(2, order[i][0]);
    }
    make_tree();
    return find(order);
}




// 이걸 누가 보게 될진 모르겠지만... 누군가에겐 참고가 됐으면 한다.
