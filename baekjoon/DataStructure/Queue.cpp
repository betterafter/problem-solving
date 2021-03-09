//
//  Queue.cpp
//  test
//
//  Created by 신기열 on 10/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
class Queue{
    
    private :
    int Frontidx;               // front 인덱스
    int Backidx;                // back 인덱스
    T* ptr;                     // 저장공간 설정
    
    
    public :
    Queue(int size);            // 생성자
    ~Queue();                   // 소멸자
    T Pop();                    // queue.pop()
    void Push(const T& val);    // queue.push()
    int Empty();                // queue.empty()
    int Size();                 // queue.size()
    int Front();
    int Back();
    
};



template <typename T>
Queue<T>::Queue(int size){
    
    Backidx = -1;               // 뒤의 인덱스는 -1로 초기 설정(스택의 topindex와 같은 방식)
    Frontidx = 0;               // 앞의 인덱스는 0부터 시작. 앞의 인덱스와 뒤의 인덱스를 비교해서 다른 연산이 실행됨.
    ptr = new T[size];          // 저장공간 선언
    
};



template <typename T>
Queue<T>::~Queue(){
    
    delete ptr;
    
};



template <typename T>
void Queue<T>::Push(const T& val){
    
    ptr[++Backidx] = val;               // 스택과 같은 방식
    
};



template <typename T>
T Queue<T>::Pop(){
    
    if(Frontidx > Backidx) return -1;   // 초기는 front = 0 이고 back = -1이므로 pop 불가능. 그 외에도 이 규칙에 의해 pop 여부 결정
    else return ptr[Frontidx++];        // front는 맨 앞의 인덱스이므로 frontidx에 해당하는 원소를 return
    
};



template <typename T>
int Queue<T>::Empty(){
    
    if(Frontidx > Backidx) return 1;    // frontidx > backidx -> 비어 있는 것을 의미
    else return 0;                      // 그렇지 않으면 0
    
};



template <typename T>
int Queue<T>::Size(){
    
    if(Frontidx > Backidx) return 0;    // 비어있으면 0
    else return Backidx - Frontidx + 1; // 그렇지 않으면 맨 앞의 인덱스 ~ 마지막 인덱스까지 개수를 세어 반환
    
};



template <typename T>
int Queue<T>::Front(){
    
    if(Frontidx > Backidx) return -1;    // 비어있으면 0
    else return ptr[Frontidx];           // 그렇지 않으면 맨 앞의 인덱스에 해당하는 원소 반환
    
};



template <typename T>
int Queue<T>::Back(){
    
    if(Frontidx > Backidx) return -1;    // 비어있으면 0
    else return ptr[Backidx];            // 그렇지 않으면 맨 뒤의 인덱스에 해당하는 원소 반환
    
};


int main(){
    
    int n, j = 0;
    cin >> n;
    
    Queue<int> Q(10000);
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
        if(s[i].compare("front") == 0){
            cout << Q.Front() << '\n';
        }
        else if(s[i].compare("back") == 0){
            cout << Q.Back() << '\n';
        }
        else if(s[i].compare("empty") == 0){
            cout << Q.Empty() << '\n';
        }
        else if(s[i].compare("pop") == 0){
            cout << Q.Pop() << '\n';
        }
        else if(s[i].compare("size") == 0){
            cout << Q.Size() << '\n';
        }
        else{
            Q.Push(stored[j]);
            j++;
        }
    }
}
