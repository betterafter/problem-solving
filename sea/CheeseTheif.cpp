#include<iostream>
#include<queue>
#include<math.h>

using namespace std;

int N, cheese[101][101];
int Visited[101][101] = { 0, };
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int BFS(){
    
    int chk = 0;
    queue<pair<int, int> > q;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(cheese[i][j] != -1 && Visited[i][j] == 0){
                
                Visited[i][j] = 1;
                chk++;
                q.push(make_pair(i, j));
                
                while(!q.empty()){
                    
                    int x = q.front().second, y = q.front().first;
                    q.pop();
                    
                    //for문 안에 q.pop을 넣으면 당연히 터진다. q 안에는 1개밖에 없는데 4번이나 빼고있으니까..
                    for(int k = 0; k < 4; k++){
                        
                        int nex = x + dir[k][1], ney = y + dir[k][0];

                        if(nex > 0 && ney > 0 && nex <= N && ney <= N && cheese[ney][nex] != -1 && Visited[ney][nex] == 0){
                            Visited[ney][nex] = 1;
                            q.push(make_pair(ney, nex));
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            Visited[i][j] = 0;
        }
    }
    
    return chk;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int answer = 0;
        cin >> N;
        
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                cin >> cheese[i][j];
            }
        }
       
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= N; j++){
                for(int k = 1; k <= N; k++){
                    if(cheese[j][k] == i){
                        cheese[j][k] = -1;
                    }
                }
            }
            answer = max(BFS(), answer);
        }
        
        if(answer == 0){
            answer++;
        }
    
        cout << "#" << test_case << " " << answer << '\n';
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
