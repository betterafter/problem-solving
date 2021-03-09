//
//  DrSpaceMan.cpp
//  test
//
//  Created by 신기열 on 18/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int test = 1; test <= T; test++){
        
        pair<string, string> dt, mt;
        string dad, mom;
        char gender;
        cin >> gender >> dad >> mom;
        
        while(1){
            
            int i = 0, j = 0;
            string temp1, temp2, temp3, temp4;
            
            while(dad[i] != '\''){
                temp1 += dad[i];
                i++;
            }
            i++;
            while(dad[i] != '\"'){
                temp2 += dad[i];
                i++;
            }
            
            while(mom[j] != '\''){
                temp3 += mom[j];
                j++;
            }
            j++;
            while(mom[j] != '\"'){
                temp4 += mom[j];
                j++;
            }
            
            dt = make_pair(temp1, temp2);
            mt = make_pair(temp3, temp4);
            
            break;
        }
        
        //cout << dt.first << " " << dt.second << " " << mt.first << " " << mt.second << '\n';
        
        int df = 0, di = 0, mf = 0, mi = 0;
        df = dt.first[0] - 48;
        mf = mt.first[0] - 48;
        
        if(dt.second.size() == 1){
            di = dt.second[0] - 48;
        }
        else if(dt.second.size() == 2){
            di = (dt.second[0] - 48) * 10 + dt.second[1] - 48;
        }
        
        if(mt.second.size() == 1){
            mi = mt.second[0] - 48;
        }
        else if(mt.second.size() == 2){
            mi = (mt.second[0] - 48) * 10 + mt.second[1] - 48;
        }
        
        //cout << df << " " << di << " " << mf << " " << mi << '\n';
        
        double res = df * 12 + mf * 12 + di + mi;
        double ansbf = 0, ansbi = 0, ansff = 0, ansfi = 0;
        
        if(gender == 'B'){
            int res1 = ceil((res + 5) / 2), res2 = floor((res + 5) / 2);
            
            ansff = (res1 - 4) / 12; ansfi = (res1 - 4) % 12;
            ansbf = (res2 + 4) / 12; ansbi = (res2 + 4) % 12;
        }
        else if(gender == 'G'){
            int res1 = ceil((res - 5) / 2), res2 = floor((res - 5) / 2);
            
            ansff = (res1 - 4) / 12; ansfi = (res1 - 4) % 12;
            ansbf = (res2 + 4) / 12; ansbi = (res2 + 4) % 12;
        }
        
        cout << "Case #" << test << ": " << ansff << "\'" << ansfi << "\"" << " to " << ansbf << "\'" << ansbi << "\"" << '\n';
        
    }
    
    
    
    
    
    
    return 0;
}
