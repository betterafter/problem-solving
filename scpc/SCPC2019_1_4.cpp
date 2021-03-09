/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>
#include <math.h>
float pipe[101];
int N; 
float result = 100000000;
float curr[101];
int used[101];
float pos[101];

using namespace std;

float getDist(float a, float b){
	float res = 0;
	res = sqrt((a + b) * (a + b) - (a - b) * (a - b));
	return res;
}

void dfs(float prevx, int used[101], float dist, float pos[101], int previdx){

	bool allChecked = true;
	for(int i = 1; i <= N; i++){
		if(used[i] == 0){
			allChecked = false; break;
		}
	}

	if(allChecked){
		if(dist < result){
			result = dist;
			for(int i = 1; i <= N; i++){
				curr[i] = pos[i];
				printf("%.20f ", curr[i]);
			}
			cout << '\n' << '\n';
			return;
		}
	}


	for(int i = 1; i <= N; i++){

		if(used[i] == 0){

			used[i] = 1; 
			if(dist == 0){ 
				pos[i] = 0;
				dfs(pos[i], used, 2 * pipe[i], pos, i);
			}
			else {
				
			}
			
			used[i] = 0; pos[i] = 0; 
		}
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		for(int i = 0; i < 101; i++){
			pipe[i] = 0;
			curr[i] = 0;
			used[i] = 0;
			pos[i] = 0;
		}

		cin >> N;
		for(int i = 1; i <= N; i++){
			cin >> pipe[i];
		}

		dfs(0, used, 0, pos, 0);
		
		cout << "Case #" << test_case+1 << endl;
		for(int i = 1; i <= N; i++){
			printf("%.20f\n", curr[i]);
		}
		//printf("%.20f\n", result);
	}

	return 0;//Your program should return 0 on normal termination.
}