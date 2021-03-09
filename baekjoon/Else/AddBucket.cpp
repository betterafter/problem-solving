//
//  AddBucket.cpp
//  test
//
//  Created by 신기열 on 03/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> num;
vector<char> op;
int n, ans = -2147483648;

int calc(int a, int b, char op){
    if(op == '+'){
        return a + b;
    }
    else if(op == '-'){
        return a - b;
    }
    else{
        return a * b;
    }
}

void DFS(int i, int _calc){

    if(i >= n / 2){
        ans = max(ans, _calc);
    }
    else{
        DFS(i + 1, calc(_calc, num[i + 1], op[i]));

        if(i + 1 < n / 2){
            int __calc = calc(num[i + 1], num[i + 2], op[i + 1]);
            DFS(i + 2, calc(_calc, __calc, op[i]));
        }
    }
}

int main(){

    cin >> n;

    string s;
    cin >> s;

    for(int i = 0; i < n; i++){
        if(s[i] != '+' && s[i] != '-' && s[i] != '*'){
            num.push_back(s[i] - 48);
        }
        else{
            op.push_back(s[i]);
        }
    }

//    ans = calc(num[0], num[1], op[0]);
//
//    for(int i = 2; i < num.size(); i++){
//        ans = calc(ans, num[i], op[i - 1]);
//    }
    //cout << ans << '\n';

    if(n == 1){
        ans = num[0];
    }
    else if(n == 3){
        ans = calc(num[0], num[1], op[0]);
    }
    else{
        DFS(0, num[0]);
    }
    
    cout << ans;

    return 0;
}
//
//#include<iostream>
//#include<string>
//
//#define endl "\n"
//#define MAX 20
//using namespace std;
//
//int N, Oper_Num;
//int Answer = -987654321987654321;
//int Num[MAX], Oper[MAX];
//
//int Bigger(int A, int B) { return A > B ? A : B; }
//
//void Input()
//{
//    cin >> N;
//    int Idx = 0;
//    int Idx2 = 0;
//
//    string Inp;
//    cin >> Inp;
//    for (int i = 0; i < Inp.length(); i++)
//    {
//        if (i % 2 == 0) Num[Idx++] = Inp[i] - '0';
//        else Oper[Idx2++] = Inp[i];
//    }
//    Oper_Num = N / 2;
//}
//
//int Calculate(int N1, int N2, char B)
//{
//    if (B == '+') return N1 + N2;
//    else if (B == '-') return N1 - N2;
//    else  return N1 * N2;
//}
//
//void DFS(int Idx, int Result)
//{
//    if (Idx >= Oper_Num)
//    {
//        Answer = Bigger(Answer, Result);
//        return;
//    }
//
//    int Cur_Result = Calculate(Result, Num[Idx + 1], Oper[Idx]);
//    DFS(Idx + 1, Cur_Result);
//
//    if (Idx + 1 < Oper_Num)
//    {
//        int After_Result = Calculate(Num[Idx + 1], Num[Idx + 2], Oper[Idx + 1]);
//        int Cur_Result = Calculate(Result, After_Result, Oper[Idx]);
//        DFS(Idx + 2, Cur_Result);
//    }
//}
//
//void Solution()
//{
//    if (N == 1)
//    {
//        cout << Num[0] << endl;
//        return;
//    }
//    else if (N == 3)
//    {
//        cout << Calculate(Num[0], Num[1], Oper[0]) << endl;
//        return;
//    }
//
//    DFS(0, Num[0]);
//    cout << Answer << endl;
//}
//
//void Solve()
//{
//    Input();
//    Solution();
//}
//
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    //freopen("Input.txt", "r", stdin);
//    Solve();
//
//    return 0;
//}
//
