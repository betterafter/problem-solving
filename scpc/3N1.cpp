#include <cstdio>
#include <iostream>

using namespace std;
int ans[70];

int main(int argc, char** argv) {

    setbuf(stdout, NULL);
    
    for (int i = 1200; i >= 1; i--)
    {
        int c = 0, x = i;
        while (x != 1)
        {
            if (x % 2 == 0) x /= 2; else x = x * 3 + 1;
            c++;
        }
        if (c <= 63) ans[c] = i;
    }
    
    
    
    int T;
    int test_case;
    
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++) {

        int k;
        scanf("%d", &k);

        printf("Case #%d\n%d %llu\n", test_case, ans[k], 1llu<<k);
        
    }
    
    return 0;    // 정상종료 시 반드시 0을 리턴해야 합니다.
}
