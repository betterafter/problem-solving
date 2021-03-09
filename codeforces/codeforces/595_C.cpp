////
////  595_C.cpp
////  CodeForce
////
////  Created by 신기열 on 01/11/2019.
////  Copyright © 2019 신기열. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//// 코드포스는 기존의 코딩테스트와는 느낌이 다르다. 꽤나 창의적인 방법으로 풀어보자.
//int main(){
//
//    int n; cin >> n;
//    while(n--){
//        long long gn, mul = 3, res = 1; cin >> gn;
//        while(res < gn){
//            // 1, 1 + 3, 1 + 3 + 3 * 3, 1 + 3 + 3 * 3 + 3 * 3 * 3 ...
//            // res은 3^n을 계속 더해줘나가면서 gn보다 커지는게 나올 때까지 계속 연산.
//            // 그 후 3^n 모음에서 어떤 것들을 빼줘야 gn보다 크면서 최소가 되는지 체크. 3^n 모음에서 빼줘도 res가 gn보다 아직 큰 것들은
//            // 빼줘도 되고, 아니면 빼주면 안되고.
//            res += mul; mul *= 3;
//        }
//        // 3^n 중에 가장 큰 것부터 뺐을 때 입력값보다 아직 크면 빼줘도 된다. 그리고 다음 3^(n-1) ... 도 반복. 만약 이 과정 속에서 작아지게
//        // 되면 그건 빼주면 안되므로 냅두고 이것보다 작은 것을 계속 탐색해준다.
//        while(mul){
//            if(res - mul >= gn){
//                res -= mul;
//            }
//            mul /= 3;
//        }
//        cout << res << '\n';
//    }
//    
//    
//
//    return 0;
//}
