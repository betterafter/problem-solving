#include <iostream>

using namespace std;

template <typename T>
inline T SQUARE(T x){
    return x * x;
}

int main(){
    cout << SQUARE(3) << '\n';
    cout << SQUARE(3.14) << '\n';
}