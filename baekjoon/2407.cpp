#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;

bool compare(string a, string b){
    int asize = a.size(), bsize = b.size(); int maxsize = max(asize, bsize);
    
    if(asize < bsize){
        for(int i = 0; i < bsize - asize; i++){
            a = '0' + a;
        }
    }
    else if(asize > bsize){
        for(int i = 0; i < asize - bsize; i++){
            b = '0' + b;
        }
    }
    for(int i = 0; i < maxsize; i++){
        if(a[i] - '0' > b[i] - '0'){
            return true;
        }
        else if(a[i] - '0' < b[i] - '0'){
            return false;
        }
    }
    return true;
}

string Add_BigInteger(string a, string b){

    string tmp = ""; int up = 0;
    int asize = a.size(), bsize = b.size(); int maxsize = max(asize, bsize);
    if(asize < bsize){
        for(int i = 0; i < bsize - asize; i++){
            a = '0' + a;
        }
    }
    else if(asize > bsize){
        for(int i = 0; i < asize - bsize; i++){
            b = '0' + b;
        }
    }

    
    for(int i = maxsize - 1; i >= 0; i--){
        int t = (b[i] - '0') + (a[i] - '0') + up;
        tmp = to_string(t % 10) + tmp;
        up = t / 10;
    }
    if(up != 0){
        tmp = to_string(up) + tmp;
    }
    return tmp;
}

string Sub_BigInteger(string a, string b){
    string tmp = ""; int down = 0;
    int asize = a.size(), bsize = b.size(); int maxsize = max(asize, bsize);

    string na = a, nb = b, ta = a, tb = b;

    if(asize < bsize){
        for(int i = 0; i < bsize - asize; i++){
            ta = '0' + ta;
        }
    }
    else if(asize > bsize){
        for(int i = 0; i < asize - bsize; i++){
            tb = '0' + tb;
        }
    }

    if(compare(a, b)){ na = ta; nb = tb; }
    else{ na = tb; nb = ta; }
    
    for(int i = maxsize - 1; i >= 0; i--){
        if(na[i] - '0' - (nb[i] - '0') - down < 0){
            int t = 10 + na[i] - '0' - (nb[i] - '0') - down; down = 1;
            tmp = to_string(t) + tmp;
        }
        else{
            int t = na[i] - '0' - (nb[i] - '0') - down; down = 0;
            tmp = to_string(t) + tmp;
        }
    }

    int i = 0; string res = "";
    while(tmp[i] == '0'){
        i++;
    }
    for(int k = i; k < tmp.size(); k++){
        res = res + tmp[k];
    }

    return res;
}

string Multi_BigInteger(string a, string b){

    string res = "";
    int asize = a.size(), bsize = b.size();
    deque<string> adder;
    for(int i = bsize - 1; i >= 0; i--){
        string tmp = ""; int up = 0;
        for(int j = asize - 1; j >= 0; j--){
            int t = (b[i] - '0') * (a[j] - '0') + up;
            tmp = to_string(t % 10) + tmp;
            up = t / 10;
        }
        if(up != 0) tmp = to_string(up) + tmp;
        for(int k = 0; k < bsize - i - 1; k++){
            tmp = tmp + '0';
        }
        adder.push_back(tmp);
    }
    while(adder.size() > 1){
        string ta = adder.front(); adder.pop_front();
        string tb = adder.front(); adder.pop_front();
        adder.push_front(Add_BigInteger(ta, tb));
    }

    return adder.front();
}

string Divde_BigInteger(string a, string b){
    
    int asize = a.size(), bsize = b.size(), maxsize = max(asize, bsize);

    string na = a, nb = b, res = "";
    if(compare(a, b)){ na = a; nb = b; }
    else{ na = b; nb = a; }

    int nasize = na.size(), nbsize = nb.size();
    string tmp = "";
    for(int i = 0; i < nbsize; i++){
        tmp = tmp + na[i];
    }
    for(int i = nbsize - 1; i < nasize; i++){
        bool isdivided = false;
        for(int t = 9; t >= 1; t--){
            string mul = Multi_BigInteger(nb, to_string(t));
            if(compare(tmp, mul)){
                isdivided = true;
                tmp = Sub_BigInteger(tmp, mul) + na[i + 1]; 
                res = res + to_string(t);
                break;
            }
        }
        if(!isdivided){
            tmp = tmp + na[i + 1];
            res = res + '0';
        }
    }
    int i = 0; string rres = "";
    while(res[i] == '0'){
        i++;
    }
    for(int k = i; k < res.size(); k++){
        rres = rres + res[k];
    }

    return rres;
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;

    string nn = to_string(n), mm = to_string(m);
    string up = "1", down = "1";

    int tmp = 0;
    while(tmp != m){
        up = Multi_BigInteger(up, Sub_BigInteger(nn, to_string(tmp))); tmp++;
    }

    int ttmp = m;
    while(ttmp >= 1){
        down = Multi_BigInteger(down, to_string(ttmp)); ttmp--;
    }

    cout << Divde_BigInteger(up, down);

    return 0;
}
