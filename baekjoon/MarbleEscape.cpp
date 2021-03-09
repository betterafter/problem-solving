////
////  MarbleEscape.cpp
////  test
////
////  Created by 신기열 on 03/06/2019.
////  Copyright © 2019 신기열. All rights reserved.
////
//#include <stdio.h>
//#include <iostream>
//#include <utility>
//#include <algorithm>
//#include <string.h>
//#include <queue>
//
//using namespace std;
//
//char c[11][11];
//int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
//int Visited[11][11] = { 0, };
//pair<int, int> hole;
//pair<int, int> r, b;
//
//
//int BFS(){
//    
//    int answer = 0;
//    
//    queue<pair<int, int> > q;
//    q.push(r);
//    
//    while(!q.empty()){
//        
//        int x = q.front().second, y = q.front().first;
//        q.pop();
//        
//        for(int i = 0; i < 4; i++){
//            int nex = red.second + dir[i][1], ney = red.first + dir[i][0];
//            int bnex = blue.second + dir[i][1], bney = blue.first + dir[i][0];
//            
//            while(c[ney][nex] != "#"){
//
//                if(c[ney][nex] == "0"){
//                    flag = 1;
//
//                    if(c[bney][bnex] == "0"){
//                        flag = 2;
//                        break;
//                    }
//                    break;
//                }
//
//                nex += dir[i][1];
//                ney += dir[i][0];
//
//                if(c[bney][bnex] != "#"){
//                    bnex += dir[i][1];
//                    bney += dir[i][0];
//                }
//            }
//            
//        }
//    }
//    
//    
//    
//}
//
//
////int DFS(int num, pair<int, int>& red, pair<int, int>& blue){
////
////    int flag = 0;
////
////    for(int i = 0; i < 4; i++){
////        int nex = red.second + dir[i][1], ney = red.first + dir[i][0];
////        int bnex = blue.second + dir[i][1], bney = blue.first + dir[i][0];
////
////        Visited[red.second][red.first] = 1;
////
////        if(c[ney][nex] != "#" && Visited[ney][nex] == 0){
////
////            while(c[ney][nex] != "#"){
////
////                if(c[ney][nex] == "0"){
////                    flag = 1;
////
////                    if(c[bney][bnex] == "0"){
////                        flag = 2;
////                        break;
////                    }
////                    break;
////                }
////
////                nex += dir[i][1];
////                ney += dir[i][0];
////
////                if(c[bney][bnex] != "#"){
////                    bnex += dir[i][1];
////                    bney += dir[i][0];
////                }
////            }
////            num++;
////        }
////
////        if(c[ney][nex] == c[r.second][r.first]){
////            num = -1;
////        }
////
////        pair<int, int> red = make_pair(ney, nex);
////        pair<int, int> blue = make_pair(bney, bnex);
////
////        if(flag == 0){
////            DFS(num, red, blue);
////        }
////        else if(flag == 1){
////            num = min(
////        }
////        else if(flag == 2){
////            return -1;
////        }
////    }
////    return num;
////}
//
//int main(){
//    
//    int N, M;
//    cin >> N >> M;
//    
//    for(int i = 1; i <= N; i++){
//        for(int j = 1; j <= M; j++){
//            cin >> c[i][j];
//            if(c[i][j] == "R"){
//                r = make_pair(i, j);
//            }
//            else if(c[i][j] == "B"){
//                b = make_pair(i, j);
//            }
//            else if(c[i][j] == "0"){
//                hole = make_pair(i, j);
//            }
//        }
//    }
//   
//    //DFS(0, r, b);
//    
//    
////    for(int i = 1; i <= N; i++){
////        for(int j = 1; j <= M; j++){
////            cout << c[i][j];
////        }
////        cout << '\n';
////    }
//    
//    
//    return 0;
//}
