// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <stack>
// #include <vector>
// #include <queue>

// using namespace std;

// int R, C;
// char m[30001][31];
// int where[30001][31];
// vector<vector<int> > block(31);


// void drop_down(int x){
//     int y = 1; 
//     while(y <= R){
//         if(m[y + 1][x] == '.'){
//             y++;
//         }
//         else if(m[y + 1][x] == 'X'){
//             m[y][x] = 'O'; break;
//         }
//         else if(m[y + 1][x] == 'O'){
//             if(x - 1 >= 0 && y + 1 <= R){
//                 if(m[y + 1][x - 1] == '.' && m[y][x - 1] == '.'){
//                     y++; x--;
//                 }
//             }
//             if(x + 1 <= C && y + 1 <= R){
//                 if(m[y + 1][x + 1] == '.' && m[y][x + 1] == '.'){
//                     y++; x++;
//                 }
//             }
//             else{
//                 m[y][x] = 'O'; break;
//             }
//         }
//         if(y == R){
//             m[y][x] = 'O'; break;
//         }
//     }
// }

// void drop_down2(int x, int y){

//     if(y == R){
//         m[y][x] = 'O'; return;
//     }

//     for(int i = y + 1; i <= R; i++){
//         if(m[i][x] == 'X'){
//             m[i - 1][x] = 'O'; return;
//         }
//         if(m[i][x] == 'O'){
//             if(x - 1 >= 0){
//                 if(m[i][x - 1] == '.' && m[i - 1][x - 1] == '.'){
//                     drop_down2(x - 1, i);
//                 }
//             }
//             if(x + 1 <= C){
//                 if(m[i][x + 1] == '.' && m[i - 1][x + 1] == '.'){
//                     drop_down2(x + 1, i);
//                 }
//             }
//             else{
//                 m[i - 1][x] = 'O'; return;
//             }
//         }
//         if(i == R){
//             m[i][x] = 'O'; return;
//         }
//     }

// }


// void drop_down3(int x, int y){

//     if(block[x].size() == 0 || block[x][block[x].size() - 1] < y){
//         m[R][x] = 'O';
//         block[x].push_back(R); return;
//     }

//     for(int i = 0; i < block[x].size(); i++){
//         if(block[x][i] > y){
//             int yy = block[x][i];
//             if(m[yy][x] == 'X'){
//                 m[yy - 1][x] = 'O';
//                 block[x].push_back(yy - 1); sort(block[x].begin(), block[x].end());
//                 return;
//             }
//             else if(m[yy][x] == 'O'){
//                 if(x - 1 >= 0){
//                     if(m[yy][x - 1] == '.' && m[yy - 1][x - 1] == '.'){
//                         drop_down3(x - 1, yy);
//                     }
//                 }
//                 if(x + 1 <= C){
//                     if(m[yy][x + 1] == '.' && m[yy - 1][x + 1] == '.'){
//                         drop_down3(x + 1, yy);
//                     }
//                 }
//                 else{
//                     m[yy - 1][x] = 'O'; 
//                     block[x].push_back(yy - 1); sort(block[x].begin(), block[x].end());
//                     return;
//                 }
//             }
//         }
//     }
// }

// void drop_down4(int x, int y){

//     if(where[y][x] == 0){
//         int yidx = y;
//         while(m[yidx][x] == '.' && yidx < R){
//             yidx++;
//         }
//         where[y][x] = yidx;
//     }

//     int yy = where[y][x];

//     if(m[yy][x] == 'X'){
//         m[yy - 1][x] = 'O';
//         where[y][x] = yy - 1; return;
//     }
//     else if(yy == R && m[yy][x] == '.'){
//         m[yy][x] = 'O';
//         where[y][x] = yy; return;
//     }
//     else if(m[yy][x] == 'O'){
//         if(x - 1 >= 0){
//             if(m[yy][x - 1] == '.' && m[yy - 1][x - 1] == '.'){
//                 drop_down4(x - 1, yy);
//             }
//         }
//         if(x + 1 <= C){
//             if(m[yy][x + 1] == '.' && m[yy - 1][x + 1] == '.'){
//                 drop_down4(x + 1, yy);
//             }
//         }
//         else{
//             m[yy - 1][x] = 'O'; 
//             where[y][x] = yy - 1; return;
//         }
//     }

// }

// void drop_down5(int x){

//     int y = where[x][1];
//     while(true){
//         if(m[y][x] != '.' && y > 1){
//             y--;
//         }
//         if(m[y][x] == 'X'){
//             where[x][1] = y - 1; m[y - 1][x] = 'O'; return;
//         }
//         if(y == R){
//             where[x][1] = y - 1; m[y - 1][x] = 'O'; return;
//         }
//         if(m[y][x] == 'O'){
//             if(x - 1 >= 0){
//                 if(m[y][x - 1] == '.' && m[y - 1][x - 1] == '.'){
                    
//                 }
//         }
//         if(x + 1 <= C){
//             if(m[yy][x + 1] == '.' && m[yy - 1][x + 1] == '.'){

//             }
//         }
//         else{
//             m[yy - 1][x] = 'O'; 
//             where[y][x] = yy - 1; return;
//         }
//         }
//     }
// }


 
// int main(int argc, char* argv[])
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);


//     cin >> R >> C;
//     for(int i = 1; i <= R; i++){
//         string s; cin >> s;
//         for(int j = 1; j <= C; j++){
//             m[i][j] = s[j - 1];
//             if(s[j - 1] == 'X'){
//                 int jj = j;
//                 while(where[i][jj] == 0 && jj >= 1){
//                     where[i][jj] = j; jj++;
//                 }
//             }
//         }
//     }
    

//     int N; cin >> N;
//     for(int i = 0; i < N; i++){
//         int pos; cin >> pos;
//         drop_down4(pos, 1);
//     }

//     for(int i = 1; i <= R; i++){
//         for(int j = 1; j <= C; j++){
//             cout << m[i][j];
//         }
//         cout << '\n';
//     }
	
 
// 	return 0;
// }
////////////////
// 실패. 문제 풀이를 이해를 못하겠음.