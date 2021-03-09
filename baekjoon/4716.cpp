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

vector<pair<int, pair<int, int> > > v;

bool compare1(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b){
    if(a.first == b.first){
        if(a.second.second == b.second.second) return a.second.first < b.second.first;
        else return a.second.second < b.second.second;
    }
    else return a.first < b.first;
}
bool compare2(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b){
    if(a.second.second == b.second.second){
        if(a.second.first == b.second.first) return a.first < b.first;
        else return a.second.second < b.second.second;
    }
    else return a.first < b.first;
}

int team, na, nb; 
int res = 987654321;

void divide(vector<pair<int, pair<int, int> > > v){

    int tmp = 0;
    for(int i = 0; i < v.size(); i++){
        int n = v[i].first, da = v[i].second.first, db = v[i].second.second;
        if(da < db){
            if(na >= n){
                tmp = tmp + n * da;
                na -= n;
            }
            else if(na < n){
                tmp = tmp + na * da; na = 0;
                tmp = tmp + (n - na) * db; nb = nb - n + na;
            }
        }
        else if(db < da){
            if(nb >= n){
                tmp = tmp + n * db; 
                nb -= n;
            }
            else if(nb < n){
                tmp = tmp + nb * db; nb = 0;
                tmp = tmp + (n - nb) * da; na = na - n + nb;
            }
        }
    }
    res = min(res, tmp);
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> team >> na >> nb;
    for(int i = 0; i < team; i++){
        int x, y, z; cin >> x >> y >> z;
        v.push_back(make_pair(x, make_pair(y, z)));
    }
    sort(v.begin(), v.end(), compare1);

    divide(v);
    cout << res;
    return 0;
}

