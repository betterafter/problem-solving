#include <iostream>

using namespace std;

char map[1001][1001];
int sum_j[1001][1001] = { 0, }; 
int sum_o[1001][1001] = { 0, }; 
int sum_i[1001][1001] = { 0, };

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int M, N, K; cin >> M >> N >> K;

    for(int i = 1; i <= M; i++){
        string s; cin >> s;
        for(int j = 0; j < N; j++){
            map[i][j + 1] = s[j];
        }
    }

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(map[i][j] == 'J'){
                sum_j[i][j] = sum_j[i - 1][j] + sum_j[i][j - 1] - sum_j[i - 1][j - 1] + 1;
                sum_o[i][j] = sum_o[i - 1][j] + sum_o[i][j - 1] - sum_o[i - 1][j - 1];
                sum_i[i][j] = sum_i[i - 1][j] + sum_i[i][j - 1] - sum_i[i - 1][j - 1];
            }
            else if(map[i][j] == 'O'){
                sum_j[i][j] = sum_j[i - 1][j] + sum_j[i][j - 1] - sum_j[i - 1][j - 1];
                sum_o[i][j] = sum_o[i - 1][j] + sum_o[i][j - 1] - sum_o[i - 1][j - 1] + 1;
                sum_i[i][j] = sum_i[i - 1][j] + sum_i[i][j - 1] - sum_i[i - 1][j - 1];
            }
            else if(map[i][j] == 'I'){
                sum_j[i][j] = sum_j[i - 1][j] + sum_j[i][j - 1] - sum_j[i - 1][j - 1];
                sum_o[i][j] = sum_o[i - 1][j] + sum_o[i][j - 1] - sum_o[i - 1][j - 1];
                sum_i[i][j] = sum_i[i - 1][j] + sum_i[i][j - 1] - sum_i[i - 1][j - 1] + 1;
            }
        }
    }

    for(int i = 0; i < K; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << sum_j[c][d] - sum_j[a - 1][d] - sum_j[c][b - 1] + sum_j[a - 1][b - 1] << ' ';
        cout << sum_o[c][d] - sum_o[a - 1][d] - sum_o[c][b - 1] + sum_o[a - 1][b - 1] << ' ';
        cout << sum_i[c][d] - sum_i[a - 1][d] - sum_i[c][b - 1] + sum_i[a - 1][b - 1] << '\n';
    }


    return 0;
}