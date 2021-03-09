////
////  598_A.cpp
////  codeforces
////
////  Created by 신기열 on 20/11/2019.
////  Copyright © 2019 신기열. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//int main(){
//    
//    int q; cin >> q;
//    for(int i = 0; i < q; i++){
//        long long a, b, n, s; cin >> a >> b >> n >> s;
//
//        if(s / n <= a){
//            s = s - (s / n) * n;
//            if(s == 0) cout << "YES" << '\n';
//            else if(b >= s){
//                cout << "YES" << '\n';
//            }
//            else cout << "NO" << '\n';
//        }
//        else if(s / n > a){
//            s = s - a * n;
//            if(b >= s) cout << "YES" << '\n';
//            else cout << "NO" << '\n';
//        }
//        
//        
//    }
//    return 0;
//}
