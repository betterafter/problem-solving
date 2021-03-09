//
//  PurchasingCard.cpp
//  test
//
//  Created by 신기열 on 30/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    
    int n, card[1001], ans[1001] = { 0, };
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> card[i];
    }
    
    ans[1] = card[1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            ans[i] = max(ans[i], ans[i - j] + card[j]);
        }
    }
    
    cout << ans[n];
    return 0;
}


//
//bool compare(const pair<float, int> &a, const pair<float, int> &b){
//    return a.first > b.first;
//}
//
//int main(){
//
//    int n, card[1001];
//    double ans = 0;
//    //float cardval[10001];
//    vector<pair<float, int> > cardval;
//    cin >> n;
//
//    for(int i = 1; i <= n; i++){
//        cin >> card[i];
//        cardval.push_back(make_pair((float)card[i] / i, i));
//    }
//
//    sort(cardval.begin(), cardval.end(), compare);
//
//    int p = 0;
//    while(n > 0){
//        if(n >= cardval[p].second){
//            ans = ans + (n / cardval[p].second) * card[cardval[p].second];
//            n = n - (n / cardval[p].second) * cardval[p].second;
//        }
//        p++;
//    }
//
//    vector<pair<float, int> > :: iterator iter;
//    for(iter = cardval.begin(); iter != cardval.end(); iter++){
//        cout << iter -> first << " ";
//    }
//    cout << ans;
//    return 0;
//}

