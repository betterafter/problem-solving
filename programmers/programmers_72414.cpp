#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long ttime[500000];
long long dp[500000];

string IntToString(int n){
    int h = n / 3600;
    int m = (n - h * 3600) / 60;
    int s = (n - (h * 3600 + m * 60));

    string sh, sm, ss;

    if(h < 10) sh = '0' + to_string(h);
    else sh = to_string(h);

    if(m < 10) sm = '0' + to_string(m);
    else sm = to_string(m);

    if(s < 10) ss = '0' + to_string(s);
    else ss = to_string(s);

    return sh + ':' + sm + ':' + ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    for(int i = 0; i < logs.size(); i++){
        string t = logs[i];

        int h = atoi((t.substr(0, 2)).c_str());
        int m = atoi((t.substr(3, 5)).c_str());
        int s = atoi((t.substr(6, 8)).c_str());
        int stime = h * 3600 + m * 60 + s;

        h = atoi((t.substr(9, 11)).c_str());
        m = atoi((t.substr(12, 14)).c_str());
        s = atoi((t.substr(15, 17)).c_str());
        int etime = h * 3600 + m * 60 + s;

        for(int j = stime + 1; j <= etime; j++){
            ttime[j]++;
        }
    }

    int ph = atoi(play_time.substr(0, 2).c_str());
    int pm = atoi(play_time.substr(3, 5).c_str());
    int ps = atoi(play_time.substr(6, 8).c_str());
    int ptime = ph * 3600 + pm * 60 + ps;

    int ah = atoi(adv_time.substr(0, 2).c_str());
    int am = atoi(adv_time.substr(3, 5).c_str());
    int as = atoi(adv_time.substr(6, 8).c_str());
    int atime = ah * 3600 + am * 60 + as;

    // 1. dp로 안하면 터짐
    // 2. long long으로 안하면 계산 이상하게 나옴
    // 3. 점 당 인원이 아닌 구간 기준으로 해야하므로 맨 앞의 점에는 인원을 카운트 안해야 함.
    dp[0] = 0;
    for(int i = 1; i <= ptime; i++){
        dp[i] = dp[i - 1] + ttime[i];
    }

    long long max = dp[atime]; 
    int m_stime = 0;
    for(int i = 1; i <= ptime - atime; i++){   
        if(max < dp[i + atime] - dp[i]){
            max = dp[i + atime] - dp[i]; m_stime = i;
        }
    }
    answer = IntToString(m_stime);
    return answer;
}