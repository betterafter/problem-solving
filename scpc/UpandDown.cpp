#include <iostream>

using namespace std;

int Answer;
int DP[1000001] = {0,};
int stackCount[1000001] = {0,};

int N1, N2;

int main(int argc, char** argv)
{
    
    int T, test_case;

    int k = 4;
    DP[1] = 0; DP[2] = 1; DP[3] = 3;
    stackCount[1] = 0; stackCount[2] = 1; stackCount[3] = 4;
    while(k <= 1000000){
        if(k % 2 == 0 && DP[k] == 0){
            
            DP[k] = DP[k / 2] + 1;
            if(DP[k - 1] == 0) DP[k - 1] = DP[k] + 1;
            
            if(stackCount[k - 1] == 0) stackCount[k - 1] = stackCount[k - 2] + DP[k - 1];
            stackCount[k] = stackCount[k - 1] + DP[k];
        }
        k++;
    }

    scanf("%d", &T);
    //cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        //cin >> N1 >> N2;
        scanf("%d %d", &N1, &N2);

        Answer = stackCount[N2] - stackCount[N1 - 1];

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
//        cout << "Case #" << test_case+1 << endl;
//        cout << Answer << '\n';
    }
    return 0;
}

