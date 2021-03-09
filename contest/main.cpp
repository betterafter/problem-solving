//
//  main.cpp
//  Contest
//
//  Created by 신기열 on 23/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int visited[101][101];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }

    queue<pair<pair<int, int>, int> > q;
    
    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            
            if(picture[y][x] == 0){
                visited[y][x] = 1;
            }
            
            else if(picture[y][x] != 0 && visited[y][x] == 0){
                
                visited[y][x] = 1;
                q.push(make_pair(make_pair(y, x), picture[y][x]));
                int curr_size_of_area = 1;
                number_of_area++;
                
                
                while(!q.empty()){
                    
                    int CurrX = q.front().first.second;
                    int CurrY = q.front().first.first;
                    int color = q.front().second;
                    q.pop();
                    
                    for(int i = 0; i < 4; i++){
                        
                        int NextX = CurrX + dir[i][1];
                        int NextY = CurrY + dir[i][0];
                        
                        visited[CurrY][CurrX] = 1;
                        
                        if(NextX >= 0 && NextY >= 0 && NextX < n && NextY < m){
                            if(visited[NextY][NextX] == 0 && picture[NextY][NextX] == color){
                                curr_size_of_area++;
                                q.push(make_pair(make_pair(NextY, NextX), picture[NextY][NextX]));
                                visited[NextY][NextX] = 1;
                                //cout << NextX << " " << NextY << '\n';
                            }
                        }
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area, curr_size_of_area);
                
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}


int main(){
    
    vector<vector<int> > test;
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(0);
    test.push_back(a);
    
    vector<int> b;
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(0);
    test.push_back(b);
    
    vector<int> c;
    c.push_back(0);
    c.push_back(0);
    c.push_back(0);
    c.push_back(1);
    test.push_back(c);
    
    vector<int> d;
    d.push_back(0);
    d.push_back(0);
    d.push_back(0);
    d.push_back(1);
    test.push_back(d);
    
    vector<int> e;
    e.push_back(0);
    e.push_back(0);
    e.push_back(0);
    e.push_back(1);
    test.push_back(e);
    
    vector<int> f;
    f.push_back(0);
    f.push_back(0);
    f.push_back(0);
    f.push_back(1);
    test.push_back(f);
    
    solution(6, 4, test);
    //cout << solution(6, 4, test)[0];
    //cout << solution(6, 4, test)[1];
    
    
    
    
    return 0;
}
