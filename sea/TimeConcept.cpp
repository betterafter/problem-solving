/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = &apos;b&apos;;
// char var[256] = &quot;ABCDEFG&quot;;
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << &quot; &quot; << c;               // float 변수 2개 출력하는 예제
// cout << d << &quot; &quot; << e << &quot; &quot; << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
     아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
     //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
     freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
     따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
     freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
     단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
     */
    //freopen(&quot;input.txt&quot;, &quot;r&quot;, stdin);
    cin>>T;
    /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
     */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        
        string s[2];
        
        for(int i = 0; i < 2; i++){
            cin >> s[i];
        }
        
        int curr_hour, curr_min, curr_sec, next_hour, next_min, next_sec, ct, nt, t;
        int ansh, ansm, anss;
        
        curr_hour = (s[0][0] - 48) * 10 + s[0][1] - 48;
        curr_min = (s[0][3] - 48) * 10 + s[0][4] - 48;
        curr_sec = (s[0][6] - 48) * 10 + s[0][7] - 48;
        
        next_hour = (s[1][0] - 48) * 10 + s[1][1] - 48;
        next_min = (s[1][3] - 48) * 10 + s[1][4] - 48;
        next_sec = (s[1][6] - 48) * 10 + s[1][7] - 48;
        
        if(next_hour == 0){
            next_hour = 24;
        }
        
        ct = curr_hour * 3600 + curr_min * 60 + curr_sec;
        nt = next_hour * 3600 + next_min * 60 + next_sec;
        
        if(nt < ct){
            t = 24 * 3600 - ct + nt;
        }
        
        else{
            t = nt - ct;
        }
        ansh = t / 3600;
        ansm = (t - ansh * 3600) / 60;
        anss = t - ansh * 3600 - ansm * 60;
        
        if(ansh == 24){
            ansh = 0;
        }
        
        string answer;
        if(ansh / 10 == 0){
            answer = "0" + to_string(ansh) + ":";
        }
        else{
            answer = to_string(ansh) + ":";
        }
        if(ansm / 10 == 0){
            answer += "0" + to_string(ansm) + ":";
        }
        else{
            answer += to_string(ansm) + ":";
        }
        if(anss / 10 == 0){
            answer += "0" + to_string(anss);
        }
        else{
            answer += to_string(anss);
        }
        
        cout << "#" << test_case << " " << answer << '\n';
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
