#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

int dp_max[200][200];
int dp_min[200][200];

// 사칙연산 

int solution(vector<string> arr)
{
	int answer = 1;
	int num = arr.size() / 2 + 1;
	memset(dp_max, -1000000, 40000);
	memset(dp_min, 1000000, 40000);

	for (int i = 0; i < num; i++) {
		dp_max[i][i] = atoi(arr[i * 2].c_str());
		dp_min[i][i] = atoi(arr[i * 2].c_str());
	}

	for (int calc = 1; calc < num; calc++) {
		for (int i = 0; i < num - calc; i++) {
			int j = calc + i;
			for (int k = i; k < j; k++) {
				if (arr[k * 2 + 1] == "-") {
					dp_max[i][j] = max(dp_max[i][k] - dp_min[k + 1][j], dp_max[i][j]);
					dp_min[i][j] = min(dp_min[i][k] - dp_max[k + 1][j], dp_min[i][j]);
				}
				else if (arr[k * 2 + 1] == "+") {
					dp_max[i][j] = max(dp_max[i][k] + dp_max[k + 1][j], dp_max[i][j]);
					dp_min[i][j] = min(dp_min[i][k] + dp_min[k + 1][j], dp_min[i][j]);
				}
			}
		}

	}
	answer = dp_max[0][num - 1];
	return answer;
}