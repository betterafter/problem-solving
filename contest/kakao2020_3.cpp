//
//  kakao2020_3.cpp
//  Contest
//
//  Created by 신기열 on 23/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// 전체적으로 정리를 안해서 소스코드가 좀 긴데, 재정비하기는 귀찮다. 어차피 알고리즘은 맞으니까 누군가 보게 된다면 새롭게 만드는 것도 나쁘지 않다고 생각한다.

// 키를 회전시키기 위한 함수. 키는 90도로 돌릴 수 있는데, 배열을 90도로 돌리면 안에 있는 데이터도 다 돌게끔 해야한다.
// 임시저장할 배열을 하나 만들어서 90도로 돌린 값을 저장하고, 이걸 다시 key에 옮겨서 return 해주도록 한다.
// 이 때 회전하는 경우는 'key 배열의 중심'을 기준으로 회전하게 된다. 우리가 알고있는 회전변환 공식은 원점을 기준으로 회전하는 것이니 배열의 중심을 기준으로
// 회전 시켜주려면 배열의 중심을 0,0으로 이동 시켜주고 회전변환을 적용한 다음, 다시 원래의 배열의 중심으로 돌아가는 방식으로 만들어줬다.
vector<vector<int> > rotateKey(vector<vector<int> > key){
    
    int mapSize = (int)(key.size());
    int roKey[mapSize][mapSize];                   // 회전한 값을 임시 저장하기 위한 배열
    double center = (mapSize - 1) / (double)2;     // 배열의 중심 좌표를 위한 변수
    
    for(int y = 0; y < key.size(); y++){
        for(int x = 0; x < key.size(); x++){
            
            // 중심을 0, 0으로 이동시켜준다.
            double roX = x - center, roY = y - center;
            
            // 회전변환 공식이
            // |cosx  -sinx|
            // |sinx   cosx|
            // 인데, 어차피 90도면 cos90 = 0, sin90 = 1이다. 이걸 특정 좌표(x,y)에 대입해 계산하면 (-y,x)가 된다.
            // 참고로 c++ 기준 cos90을 하면 0이 아닌 0.00000e... 뭐 이런값이 나오는데, 아마 변환이 따로 필요할 것이라 생각한다.
            int resX = (int)(-roY + center);
            int resY = (int)(roX + center);

            // 임시저장배열에 하나씩 저장하도록 하자.
            roKey[resY][resX] = key[y][x];

        }
    }
    
    // 이걸 key에 다시 옮겨주고 return 해주도록 한다.
    for(int y = 0; y < key.size(); y++){
        for (int x = 0; x < key.size(); x++){
            key[y][x] = roKey[y][x];
        }
    }

    return key;
}



bool solution(vector<vector<int> > key, vector<vector<int> > lock){
    
    int locksize = (int)lock.size();
    int keysize = (int)key.size();
    
    int locknum = 0;
    vector<vector<int> > tmpkey;
    
    tmpkey = key;                                // 90도 회전에 의해 key값이 계속 바뀌게 되는데, 그것을 저장하기 위한 tmpkey
    
    // 자물쇠에 홈이 몇개있는지 체크해준다. x, y 좌표 이동을 하면서 홈에 제대로 맞물리면 하나씩 빼주면서 홈의 개수가 0이 되면 열 수 있는 것이다.
    for(int y = 0; y < locksize; y++){
        for(int x = 0; x < locksize; x++){
            if(lock[y][x] == 0) locknum++;
        }
    }

    // 4개를 돌려주는 이유는 0도, 90도, 180도, 270도로 돌릴 수 있기 때문
    for(int i = 0; i < 4; i++){
        
        tmpkey = rotateKey(tmpkey);
        vector<pair<int, int> > keynum;
        int tmplocknum = locknum;
        int flag = 0;

        // 키의 튀어나온 부분의 상대적인 위치만 저장해서 좌표 이동을 하면서 자물쇠 구멍에 전부 들어맞는지만 파악하면 된다. 굳이 열쇠의 모든 배열을 대조할 필요없다.
        for(int y = 0; y < keysize; y++){
            for(int x = 0; x < keysize; x++){
                if(tmpkey[y][x] == 1) keynum.push_back(make_pair(y, x));
            }
        }

        // 문제를 보면 자물쇠의 범위가 20 * 20 으로 그렇게 크지 않다. 어차피 자물쇠 범위를 벗어나는건 체크할 필요없으니 자물쇠의 처음부터 끝까지 이동하면서 맞물리는 경우가 있는지 전부 체크해주면 된다.
        for(int y = 0; y <= 20; y++){
            for(int x = 0; x <= 20; x++){
                
                // tmplocknum은 현재 검사하고 있는 자물쇠의 홈 부분을 하나씩 빼주기 위한 임시변수
                tmplocknum = locknum;
                flag = 0;
                
                // +x, +y 만큼 이동한 경우 keynum에 저장된 모든 열쇠의 돌기 부분이 홈에 맞물리면서 자물쇠의 돌기 부분에 닿지 않은지 체크해준다.
                // keynum은 0부터 자물쇠의 크기에 벗어나지 않는 부분만 체크해준다.
                for(int z = 0; z < keynum.size(); z++){

                    if(keynum[z].first + y >= 0 && keynum[z].second + x >= 0 && keynum[z].first + y < locksize && keynum[z].second + x < locksize){
                        
                        if(lock[keynum[z].first + y][keynum[z].second + x] == 0){
                            tmplocknum--;
                        }
                        else{ flag = 1; break; }
                    }
                }
                
                if(flag == 0 && tmplocknum == 0) return true;
                
                
                tmplocknum = locknum;
                flag = 0;
                
                // -x, -y 만큼 이동한 경우
                for(int z = 0; z < keynum.size(); z++){

                    if(keynum[z].first - y >= 0 && keynum[z].second - x >= 0 && keynum[z].first - y < locksize && keynum[z].second - x < locksize){
                        
                        if(lock[keynum[z].first - y][keynum[z].second - x] == 0){
                            tmplocknum--;
                        }
                        else{ flag = 1; break; }
                        
                    }
                }
                if(flag == 0 && tmplocknum == 0) return true;
                
                tmplocknum = locknum;
                flag = 0;
                
                // -y, +x 만큼 이동한 경우
                for(int z = 0; z < keynum.size(); z++){

                    if(keynum[z].first - y >= 0 && keynum[z].second + x >= 0 && keynum[z].first - y < locksize && keynum[z].second + x < locksize){
                        
                        if(lock[keynum[z].first - y][keynum[z].second + x] == 0){
                            tmplocknum--;
                        }
                        else{ flag = 1; break; }
                        
                    }
                }
                if(flag == 0 && tmplocknum == 0) return true;
                
                tmplocknum = locknum;
                flag = 0;
                
                // +y, -x 만큼 이동한 경우
                for(int z = 0; z < keynum.size(); z++){

                    if(keynum[z].first + y >= 0 && keynum[z].second - x >= 0 && keynum[z].first + y < locksize && keynum[z].second - x < locksize){
                        
                        if(lock[keynum[z].first + y][keynum[z].second - x] == 0){
                            tmplocknum--;
                        }
                        else{ flag = 1; break; }
                        
                    }
                }
                if(flag == 0 && tmplocknum == 0) return true;
            }
        }
    }
    
    // 전부 다 체크해줬는데도 true로 return 되지 않았다면 그냥 없는 거다. false를 return 해주도록 하자.
    return false;
}

// 키랑 맵의 크기가 다를 수 있다는 점 유의해두도록 하자.
// x, y 좌표를 움직이는 연산을 잘 생각하자. +x, +y 와 -x, -y 만 생각해서 구현해서 시간이 많이 걸렸다.




int main(){
    

    vector<vector<int> > testkey;
    vector<vector<int> > testlock;
    
    vector<int> test1;
    test1.push_back(0);
    test1.push_back(0);
    test1.push_back(0);
    test1.push_back(0);
    
    vector<int> test2;
    test2.push_back(1);
    test2.push_back(0);
    test2.push_back(0);
    test2.push_back(0);
    
    vector<int> test3;
    test3.push_back(0);
    test3.push_back(1);
    test3.push_back(1);
    test3.push_back(0);
    
    vector<int> test8;
    test8.push_back(0);
    test8.push_back(1);
    test8.push_back(1);
    test8.push_back(0);
    
    testkey.push_back(test1);
    testkey.push_back(test2);
    testkey.push_back(test3);
    testkey.push_back(test8);
    
    vector<int> test4;
    test4.push_back(1);
    test4.push_back(1);
    test4.push_back(1);
    test4.push_back(1);
    
    vector<int> test5;
    test5.push_back(1);
    test5.push_back(1);
    test5.push_back(0);
    test5.push_back(0);
    
    vector<int> test6;
    test6.push_back(1);
    test6.push_back(0);
    test6.push_back(1);
    test6.push_back(0);
    
    vector<int> test7;
    test7.push_back(1);
    test7.push_back(0);
    test7.push_back(1);
    test7.push_back(0);
    
    testlock.push_back(test4);
    testlock.push_back(test5);
    testlock.push_back(test6);
    testlock.push_back(test7);
    
    //solution(testkey, testlock);
    
    if(solution(testkey, testlock) == 1) cout << "true";
    else cout << "false";
    //cout << solution();

    return 0;
}
// 키랑 맵의 크기가 다를 수 있다는 점 유의해두도록 하자.
// x, y 좌표를 움직이는 연산을 잘 생각하자. +x, +y 와 -x, -y 만 생각해서 구현해서 시간이 많이 걸렸다.
