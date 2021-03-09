//
//  Stack.cpp
//  test
//
//  Created by 신기열 on 09/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
class Stack{
    
    private :
    int Topidx;                 // top의 인덱스
    T* ptr;                     // 저장공간 설정
    
    
    public :
    Stack(int size);            // 생성자
    ~Stack();                   // 소멸자
    T Pop();                    // stack.pop()
    void Push(const T& val);    // stack.push()
    int Empty();                // stack.empty()
    int Top();                  // stack.top()
    int Size();                 // stack.size()

};



template <typename T>
Stack<T>::Stack(int size){
    
    Topidx = -1;                // 배열은 인덱스가 0부터이므로 -1로 초기 설정
    ptr = new T[size];          // 저장공간 선언
    
};



template <typename T>
Stack<T>::~Stack(){
    
    delete ptr;
    
};



template <typename T>
void Stack<T>::Push(const T& val){
    
    ptr[++Topidx] = val;        // 생성자에서 -1로 초기설정해 준 이유. 예외 없이 인덱스를 더해줌
    
};



template <typename T>
T Stack<T>::Pop(){
    
    if(Topidx < 0) return -1;   // Topidx < 0 --> Topidx = -1 --> 스택이 비어있음
    else return ptr[Topidx--];  // 비어있지 않으면 제일 윗부분을 빼고 뺀 정수를 출력
    
};



template <typename T>
int Stack<T>::Empty(){
    
    if(Topidx < 0) return 1;    // 비어있으면 1
    else return 0;              // 그렇지 않으면 0
    
};



template <typename T>
int Stack<T>::Top(){
    
    if(Topidx < 0) return -1;   // 비어있으면 -1
    else return ptr[Topidx];    // 그렇지 않으면 제일 위의 정수 출력
    
};



template <typename T>
int Stack<T>::Size(){
    
    if(Topidx < 0) return 0;    // 비어있으면 0
    else return Topidx + 1;     // 그렇지 않으면 가장 위의 인덱스 + 1 (예를 들어 인덱스가 0이면 1개인거니까)
    
};

int main(){
    
    int n, j = 0;
    cin >> n;
    
    Stack<int> S(10000);
    int stored[10000];
    string s[10001];
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(s[i].compare("push") == 0){
            cin >> stored[j];
            j++;
        }
    }

    j = 0;
    for(int i = 0; i < n; i++){
        if(s[i].compare("top") == 0){
            cout << S.Top() << '\n';
        }
        else if(s[i].compare("empty") == 0){
            cout << S.Empty() << '\n';
        }
        else if(s[i].compare("pop") == 0){
            cout << S.Pop() << '\n';
        }
        else if(s[i].compare("size") == 0){
            cout << S.Size() << '\n';
        }
        else{
            S.Push(stored[j]);
            j++;
        }
    }
}
