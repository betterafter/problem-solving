#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

long long gcd(long long x, long long y){
	long long t;
	long long a = max(x, y), b = min(x, y); 
	while(b != 0){
		t = a % b;
		a = b; b = t;
	}
	return a;
}

void check1(long long a, long long b){

    clock_t start, end;

    start = clock();
    int x = max(a, b), y = min(a, b);
    vector<long long> div;

    int i = 1, j = 1;
    long long mul = y;
    while(true){
        div.push_back(x * j);
        while(mul * i <= x * j){
            for(int k = 0; k < div.size(); k++){
                if(div[k] == mul * i){
                    cout << div[k] << '\n'; 
                    end = clock();
                    cout << "첫번째 방법 : " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
                    return;
                }
            }
            i++;
        }
        j++;
    } 
}


int main(int argc, char* argv[])
{


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
    
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        clock_t start, end;
        int a, b; cin >> a >> b;

        check1(a, b);

        start = clock();
        cout << a * b / gcd(a, b) << '\n';
        end = clock();
        cout << "두번째 방법 : " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
    }
	


 
	return 0;
}