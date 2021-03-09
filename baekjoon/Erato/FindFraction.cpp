//
//  FindFraction.cpp
//  test
//
//  Created by 신기열 on 07/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int x, curr = 1, cnt = 1;
    cin >> x;
    
    if(x == 1){
        cout << 1 << "/" << 1;
    }
    
    else{
        while(1){
            if(x <= curr + cnt * 2){
                
                if((cnt+1) % 2 == 0){
                    for(int i = 0; i <= cnt; i++){
                        if(x == curr + cnt + i){
                            cout << (i + 1) << "/" << cnt - i + 1;
                            break;
                        }
                    }
                }
                else if((cnt+1) % 2 != 0){
                    for(int i = 0; i <= cnt; i++){
                        if(x == curr + cnt + i){
                            cout << cnt - i + 1 << "/" << (i + 1);
                            break;
                        }
                    }
                }
                
                break;
            }
            
            else{
                curr += cnt;
                cnt++;
            }
        }
    }
    return 0;
}
