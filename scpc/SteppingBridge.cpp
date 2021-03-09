//
//  SteppingBridge.cpp
//  SCPC
//
//  Created by 신기열 on 19/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <iostream>
#define MOD 1000000009

int cnt[50001];
int step[50001][101];
bool IsMine[50001];

int steprock, jump, mine;

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    int T, test_case;
    Answer = 0;
    
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        cin >> steprock >> jump >> mine;
        
        for(int i = 0; i <= 50001; i++){
            cnt[i] = 0;
            for(int j = 0; j <= 101; j++){
                step[i][j] = 0;
            }
        }
        
        for(int i = 0; i <= 50001; i++){
            IsMine[i] = false;
        }

        for(int i = 1; i <= mine; i++){
            int mine_pos;
            cin >> mine_pos;
            IsMine[mine_pos] = true;
        }
        
        
        cnt[0] = 1;
        
        for(int i = 1; i <= steprock; i++){
            if(!IsMine[i]){
                // 점프가 돌 수보다 더 클 수도 있고 작을 수도 있음
                for(int j = 1; j <= jump && (i - j >= 0); j++){
                    step[i][j] = (cnt[i - j] + MOD - step[i - j][j]) % MOD;
                    cnt[i] = (step[i][j] + cnt[i]) % MOD;
                }
            }
        }
        
        Answer = cnt[steprock];
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
}

//int main(int argc, char** argv)
//{
//    int T, test_case;
//    Answer = 0;
//
//    cin >> T;
//    for(test_case = 0; test_case  < T; test_case++)
//    {
//        vector<int> step[MAX];
//        int cnt[MAX] = { 0, }, IsMine[MAX] = { 0, };
//        int steprock, jump, mine, mine_pos;
//        cin >> steprock >> jump >> mine;
//
//        if(mine > 0){
//            for(int i = 1; i <= mine; i++){
//                cin >> mine_pos;
//                IsMine[mine_pos] = -1;
//            }
//        }
//
//        for(int i = 1; i <= MAX; i++){
//
//            step[i].reserve(101);
//
//            if(i == 1 && IsMine[i] != -1){ step[i][0] = 1; cnt[1] = 1; }
//            else{
//                for(int j = 0; j < i; j++){
//
//                    if(IsMine[i] != -1){
//                        if(i - j <= jump){
//                            if(j == 0){ step[i][j] = 1; cnt[i]++; }
//                            else if(j != 0 && IsMine[j] != -1){
//                                step[i][j] = cnt[j];
//                                cnt[i] = cnt[i] + step[i][j];
//                                if(j >= 2){
//                                    cnt[i] = cnt[i] - step[j][j - (i - j)];
//                                }
//                            }
//                            else if(j != 0 && IsMine[j] == -1){
//                                step[i][j] = 0;
//                            }
//                        }
//                        else if(i - j > jump){
//                            step[i][j] = 0;
//                        }
//                    }
//                }
//            }
//        }
//
//        Answer = cnt[steprock];
//
//        cout << "Case #" << test_case+1 << endl;
//        cout << Answer << endl;
//    }
//
//    return 0;
//}



