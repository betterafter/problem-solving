#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int Answer;
int map[51][501];
queue<pair<int, int> > bq;
vector<pair<int, int> > ans;




void BFS(){

    while(!bq.empty()){
        
        pair<int, int> pos; int dest = 0;
        int x = bq.front().second, y = bq.front().first;
        bq.pop();

        if(map[y][x] == 1){
            
            //cout << y << " " << x <<  '\n';
            
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    if(x + j >= 1 && x + j <= N && y + i >= 1 && y + i <= M){
                        int cnt = 0;



                        for(int p = -1; p < 2; p++){
                            for(int q = -1; q < 2; q++){
                                if(x + j + q >= 1 && x + j + q <= N && y + i + p >= 1 && y + i + p <= M){
                                    if(map[y + i + p][x + j + q] == 1) cnt++;
                                }
                            }
                        }


                        if(dest <= cnt && x + j - 1 >= 1 && x + j - 1 <= N && y + i - 1 >= 1 && y + i - 1 <= M){

                            pos.first = y + i ; pos.second = x + j ;
                            dest = cnt;
                        }
                        
                        //cout << y + i << " " << x + j << " " << cnt << '\n';

                    }//if
                }//for
            }//for
            
            //cout << "res : " << pos.first << " " << pos.second << '\n';
            map[pos.first][pos.second] = 3;
            
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    if(pos.second + j >= 1 && pos.second + j <= N && pos.first + i >= 1 && pos.first + i <= M && map[pos.first + i][pos.second + j] == 1){
                        map[pos.first + i][pos.second + j] = 2;
                    }
                }
            }
            ans.push_back(make_pair(pos.first - 1, pos.second - 1));
            Answer++;
            
//            for(int i = 1; i <= M; i++){
//                for(int j = 1; j <= N; j++){
//                    cout << map[i][j];
//                }
//                cout << '\n';
//            }
//            cout << '\n';
        }
    }//while

}






int main(int argc, char** argv)
{
    int T, test_case;
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        cin >> M >> N;
        for(int i = 1; i <= M; i++){
            string s;
            cin >> s;
            for(int j = 1; j <= N; j++){
                map[i][j] = s[j - 1] - 48;
                if(map[i][j] == 1) bq.push(make_pair(i, j));
            }
        }

        BFS();
        
        
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
        for(int i = 0; i < Answer; i++){
            cout << ans[i].first << " " << ans[i].second << '\n';
        }
        
        ans.clear();
    }
    
    return 0;
}
