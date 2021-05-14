#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool solution(int n) {
    bool answer=false;
    int num=1;
    int ans=0;
    int temp=10;
    int tem=10;
    
    //n의 자리수 구하기
    // for(int i=1; i<9;i++){
    //     if(n/temp < 0 )
    //         break;
    //     else{
    //         temp=temp*10;
    //         num++;
    //     }
    // }

    int t = n;
    while(t / temp > 0){
        t /= temp;
        num++;
    }
    

//n의 각 자리의 합 구하기
// for(int i=0; i<num; i++)
//     { ans = ans + n%tem;
//     n = (n-(n%tem))/10;
//     }
    t = n;
    for(int i = 0; i < num; i++){
        ans = ans + t % temp;
        t /= temp;
    }
    
    cout << n << " " << ans;

   //하샤드 수인지 판별 
 if(n % ans != 0)
    return false;
 else
     return true;
       
    
    
}

int main(){

    if(!solution(1234)) cout << "false";
    else cout << "true";

    return 0;
}