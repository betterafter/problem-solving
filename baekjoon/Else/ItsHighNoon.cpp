//
//  ItsHighNoon.cpp
//  test
//
//  Created by 신기열 on 13/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <queue>

#define ull unsigned long long

using namespace std;

int main(){
    
    int n, flag = 0;
    vector<pair<double, double> > pos;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        double x, y;
        scanf("%lf%lf", &x, &y);

        pos.push_back(make_pair(x, y));
    }
    
    if(n <= 4) cout << "success";
    
    else{
        pair<double, double> stan = pos[0];
        
        for(int i = 1; i < pos.size(); i++){
            
            int cnt1 = 1, cnt2 = 0;
            double incline;
            if(stan.second - pos[i].second == 0) incline = 0;
            else if(stan.first - pos[i].first == 0) incline = 1;
            else incline = (stan.first - pos[i].first) / (stan.second - pos[i].second);
            
            queue<pair<double, double> > temp;
            queue<double> inc;

            for(int j = 1; j < pos.size(); j++){

                double in;
                if(stan.second - pos[j].second == 0) in = 0;
                else if(stan.first - pos[j].first == 0) in = 1;
                else in = (stan.first - pos[j].first) / (stan.second - pos[j].second);

                //cout << i << " : " << incline << " " << in << '\n';
                if(in == incline) cnt1++;
                else if(in != incline){

                    temp.push(make_pair(pos[j].first, pos[j].second));
                    //cout << pos[j].first << pos[j].second << '\n';
                    
                    if(temp.size() == 2){
                        double tempx = temp.front().first, tempy = temp.front().second;
                        temp.pop();
                        double tempx2 = temp.front().first, tempy2 = temp.front().second;
                        
                        double intemp;
                        if(tempy - tempy2 == 0) intemp = 0;
                        else if(tempx - tempx2 == 0) intemp = 1;
                        else intemp = (tempx - tempx2) / (tempy - tempy2);
                        inc.push(intemp);

                        if(intemp == inc.front()) cnt2++;
                        else if(intemp != inc.front()){
                            flag = 1; break;
                        }
                    }
                }
            }
            //cout << '\n' << "flag : " << flag << '\n';
            if((cnt1 >= 10 || cnt2 >= 10) && flag == 1){ cout << "failure"; break; }
            else if(i == pos.size() - 1 && flag == 1){ cout << "failure"; break; }
            else if(flag == 0){ cout << "success"; break; }
            else{ flag = 0; }
        }
    }
    return 0;
}
