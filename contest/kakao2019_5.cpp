#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> pre, post;
// 문제의 예시로 설명하겠다.
// 
// 10
// 9
// 8
// 7
// 6                                  (7)
// 5              (4)                              (2)
// 4
// 3      (6)             (1)                                (3)
// 2          (9)                 (8)
// 1                          (5)
// 0  
//     0   1   2   3   4   5   6   7   8   9   10   11   12   13   14  
// 
//
// 이렇게 직관적으로 예상할 수 있는 문제는 묘하게 구현하기 힘들다..
// 9번은 뭔가 6번 바로 밑에 있으니 6번 자식이겠구나 싶은데, 그걸 어떻게 알고리즘으로 나타낼지 생각하는게 힘들었다.
// 잘 보면 6번의 오른쪽 자식이 될 수 있는 노드는 6번과 4번 사이의 x값이 되겠다. 4번을 넘어버리는 순간 9번이 6번의 자식이 되면 트리의 형태가 안되니까.
// 즉 6번의 왼쪽 자식 노드는 x = 0일 테고, 오른쪽 자식 노드는 1 < x < 3이며,
// 4번의 왼쪽 자식 노드는 0 < x < 2 이며, 오른쪽 자식 노드는 4 < x < 7 (4번의 부모 노드의 x값 바로 전까지) 가 되겠다.
// 즉, 아래와 같은 범위를 가지게 된다.
// 왼쪽 자식 노드의 범위 : (부모 노드의 x값 ~ 자신의 x 값)      오른쪽 자식 노드의 범위 : (자신의 x 값 ~ 부모의 부모 노드의 x값)  
// 그런데 매 탐색마다 부모와 조부모의 x값을 체크할 순 없으니까 자식 노드에 그 자식 노드가 가질 수 있는 왼쪽과 오른쪽 자식 노드의 x 값의 최대, 최소를
// 넣어 보내면 된다.
// 즉 6번이 9번을 연결할 때 9번은 6번의 x ~ 4번의 x 사이에서만 자식을 가질 수 있으므로 1 초과 3 미만의 범위를 보내주면 되겠다.    


class node{
    public :
    int x, y, childLevel, idx, nidx;
    // 범위에 대한 값. 해당 노드의 자식노드가 될 수 있는 x 값의 범위. 즉 min 초과 max 미만
    int max, min;
    node *left, *right;


    void searchNode(vector<node *> n){

        childLevel = -1;
        // 직계 자식 y값 찾기. 해당 트리 노드는 y 레벨로 정렬되어 있으므로 순서대로 탐색 도중에 y 값이 달라지는 순간이 자식 노드 레벨이 된다.
        // 이 때 탐색을 바로 멈춰주면 된다.
        for(int i = 0; i < n.size(); i++){
            if(n[i] -> y < y){
                childLevel = n[i] -> y; break;
            }
        }
        if(childLevel >= 0){
            for(int i = nidx; i < n.size(); i++){
                // 직계 자손일 때
                if(n[i] -> y == childLevel){
                    // 왼쪽 ~ 현재 노드 사이일때
                    if(n[i] -> x >= min && n[i] -> x < x){
                        // 왼쪽 자식 노드의 x 값은 최소는 그대로 보내면 되고 (원래 min 초과였으니까) 최대는 부모의 x 보다 작은 값부터 시작
                        left = n[i]; left -> min = min; left -> max = x - 1;
                        // 해당 왼쪽 자식 노드에 대해서도 자식 노드 찾기를 재귀적으로 탐색
                        left -> searchNode(n);
                    }

                    // 현재노드 ~ 오른쪽 사이일 때
                    else if(n[i] -> x > x && n[i] -> x <= max){
                        // 마찬가지고 부모보다 큰 값 ~ max 까지
                        right = n[i]; right -> min = x + 1; right -> max = max;
                        right -> searchNode(n);
                    }
                }
            }
        }
    }
    // 전위 순회
    void preorder(){
        pre.push_back(idx);
        if(left != NULL) left -> preorder();
        if(right != NULL) right -> preorder();
    }
    // 후위 순회
    void postorder(){
        if(left != NULL) left -> postorder();
        if(right != NULL) right -> postorder();
        post.push_back(idx);
    }
    // 전위 순회와 후위 순회에 대해 모른다면 트리에 대해 다시 공부를 해야 한다. 간단하게 말하면 전위 순회는 왼쪽부터 탐색하는 것이고,
    // 후위 순회는 맨 아래의 왼쪽 -> 오른쪽 순서로 탐새하는 것이다.  
};


bool compare(node *a, node *b){
    if(a -> y != b -> y){
        return a -> y > b -> y;
    }
    else return a -> x < b -> x;
}



vector<vector<int> > solution(vector<vector<int> > nodeinfo) {
    vector<vector<int> > answer;
    vector<node *> n;
    
    //[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]
    // -> [[8,6],[3,5],[11,5],[1,3],[5,3],[13,3],[2,2],[7,2],[6,1]]

    // 모든 노드에 대해 자신의 좌표와 자신의 번호에 대한 정보를 넣어준다.
    for(int i = 0; i < nodeinfo.size(); i++){
        node *treenode = new node();
        treenode -> x = nodeinfo[i][0];
        treenode -> y = nodeinfo[i][1];
        treenode -> idx = i + 1;
        n.push_back(treenode);
    }
    // y가 큰 순서, x가 작은 순서로 정렬해준다.
    sort(n.begin(), n.end(), compare);
    for(int i = 0; i < n.size(); i++){
        n[i] -> nidx = i;
    }
    // 조상 노드의 최대 최소를 그냥 넉넉하게 잡았다.
    n[0] -> min = 0; n[0] -> max = 100000;
    n[0] -> searchNode(n);

    n[0] -> preorder();
    n[0] -> postorder();

    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}