#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

static string bodyStart = "<body>";
static string bodyEnd = "</body>";

static string linkStart = "<a href=\"";
static string linkEnd = "</a>";

static string meta = "<meta property=\"og:url\" content=\"";

string urlindex[100];
double score[100];
double basicscore[100];

vector<vector<string> > externlink;


bool cmp(const pair<int, double> a, const pair<int, double> b){
    if(a.second == b.second){
        return a.first < b.first;
    }else{
        return a.second > b.second;    
    }
}


int solution(string word, vector<string> pages) {

    int size = pages.size();

    // word 전부 소문자로 바꾸기
    for(int i = 0; i < word.size(); i++){
        if(word[i] >= 'A' && word[i] <= 'Z') word[i] = tolower(word[i]);
    }
 

    for(int i = 0; i < size; i++){

        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);

        // 현재 링크 이름 찾기/////////////////////////////////////////////////////////////////////////////////

        // "<meta property=\"og:url\" content=\"" 에 대한 시작 인덱스를 찾고, end에 해당 문자열이 끝나는 지점을 선언하고,
        int start = pages[i].find(meta);
        int end = start + meta.size();
        string thislink = "";
        // 그 지점으로부터 " 가 나올때까지 탐색해서 현재 링크를 구해준다.
        while(pages[i][end] != '\"'){
            thislink = thislink + pages[i][end];
            end++;
        }
        // 현재 링크는 urlindex에 넣어준다.
        urlindex[i] = thislink;


        // 해당 코드는 별 의미는 없지만, 혹시라도 써먹을 수도 있어서 일단 그냥 냅뒀다.
        // 내용 찾기///////////////////////////////////////////////////////////////////////////////////////
        // int bodyindex = pages[i].find(bodyStart) + bodyStart.size();
        // int bodyendindex = pages[i].find(bodyEnd, bodyindex);

        // string content = "";
        // if(bodyindex != string::npos){
        //     while(bodyindex != bodyendindex){
        //         content = content + pages[i][bodyindex];
        //         bodyindex++;
        //     }
        // }
        ///////////////////////////////////////////////////////////////////////////////////////////////////




        // 외부링크 찾기//////////////////////////////////////////////////////////////////////////////////////
        vector<string> externallink;
        int externallinkidx = 0;
        // 해당 pages에 "<a href=\"" 형식이 존재한다면
        while((externallinkidx = pages[i].find(linkStart, externallinkidx)) != std::string::npos){
            externallinkidx = externallinkidx + linkStart.size();
            // 위의 링크를 구한 것 처럼 외부링크를 구해주고
            string externallinks = "";
            while(pages[i][externallinkidx] != '\"'){
                externallinks = externallinks + pages[i][externallinkidx];
                externallinkidx++;
            }
            // 임시 위부링크 벡터에 해당 외부링크 문자열을 넣어준다. 
            externallink.push_back(externallinks);
            // 모든 외부링크를 찾을 때까지 반복해준다.
        }
        // 임시 외부링크의 벡터를 외부링크 모음 벡터에 넣어준다.
        externlink.push_back(externallink);
        ///////////////////////////////////////////////////////////////////////////////////////////////////




        // 단어 찾기/////////////////////////////////////////////////////////////////////////////////////////
        // 일단 body가 시작되는 지점부터 탐색해야한다.
        // 근데 사실 findidx를 0으로 해서 탐색해도 정답으로 처리된다. 아마 문제 자체가 찾고자 하는 단어는 body 안에 있다는 것을 전제로 깔고
        // 들어가는 것 같은데, 그래도 혹시 모르니까 body부터 시작하도록 하자.
        // 그리고 좀 더 정확히는, <a> 같은 것도 양 옆이 알파벳이 아니여서 찾고자 하는 문자로 취급 될 수도 있는데, 그런 것 까지는 생각 안했나보다.
        // 좀 더 정확히하려면 당연히 해당 부분도 예외처리를 해야한다.
        int findidx = pages[i].find(bodyStart);
        float currscore = 0;
        // 해당 단어를 찾아서,
        while((findidx = pages[i].find(word, findidx)) != string::npos){
            // 왼쪽이 알파벳이거나, 오른쪽이 알파벳이면
            if((pages[i][findidx - 1] >= 'a' && pages[i][findidx - 1] <= 'z') ||
                (pages[i][(findidx + word.length())] >= 'a' && pages[i][(findidx + word.length())] <= 'z')){
                // 그냥 탐색 인덱스만 단어 다음으로 옮겨준다.
                findidx += word.length();
            }
            // 만약 양 옆이 알파벳이 아니면, 기본 점수를 1 올려준다. 
            else{
                currscore++;
                findidx += word.length();
            }
        }
        // 해당 탐색으로 얻은 총 점수를 기본 점수로 정해준다.
        basicscore[i] = currscore;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }



    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! error 1 : testcase 13, 16번 에러 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for(int idx = 0; idx < size; idx++){
        vector<int> xx;
        // 일단 총 점수에 기본 점수를 더해준다.
        score[idx] += basicscore[idx];

        // urlindex의 링크와 각 웹페이지가 가지는 외부링크들을 비교해서
        for(int i = 0; i < externlink[idx].size(); i++){
            for(int j = 0; j < size; j++){
                // 웹페이지의 내부 링크가 외부링크에 존재한다면
                if(externlink[idx][i].compare(urlindex[j]) == 0){
                    //score[j] += (double)basicscore[idx] / (double)externlink[idx].size();
                    // xx에 그 링크의 인덱스를 넣어준다.
                    xx.push_back(j);
                }
            }
        }
        // 왜 xx.size() 와 externlink[idx].size() 가 다를까? 
        // externlink 에 들어가 있는 링크는 pages에 있는 링크와 연결된 외부링크가 있을 수도 있고 어디에도 연결되어있지 않은 링크가 있을 수도 있음.
        // 하지만 링크 점수는 연결이 되어있는 링크건, 어디에도 연결되어있지 않은 링크건 간에 나누는 수에 포함되어야함.
        // 그래서 xx에는 pages 내에 있는 특정 링크에 연결 되어있는 링크만 넣은 거여서 정작 externlink 안에 있는 모든 링크가 들어있지는 않음.
        // 따라서 xx.size()로 나누는 건 연결 된 링크 수만으로 나누는 것이므로 전체 수인 externlink[idx].size()로 나눠줘야함.
        // 아니면 위에 주석처럼 score[j] += (double)basicscore[idx] / (double)externlink[idx].size(); 이걸 실시간으로 보내줘도 상관없음.
        if(xx.size() > 0){
            // 해당 링크에 대한 링크 점수를 구해준다.
            for(int k = 0; k < xx.size(); k++){
                score[xx[k]] += (double)basicscore[idx] / (double)externlink[idx].size();
            }
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // 해당 인덱스와 총 점수를 묶어준다.
    pair<int, double> p[100];
    for(int i = 0; i < size; i++){
        p[i] = make_pair(i, score[i]);
    }

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! error 2 : testcase 17번 에러 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    // 처음에 cmp를 float으로 했는데 double로 고치니까 해결됨. 알고리즘 자체는 문제가 아니였는데 형변환에서 어떤 문제가 생기는 듯.
    // 애매하면 그냥 p 배열을 sort로 처리하자. (밑에 주석 처리해 놓음)
    // float과 double에 대해서 다른 점이 이 링크에 있는데, 한번 참고해도 좋을 것 같다.
    // https://hashcode.co.kr/questions/553/float%EA%B3%BC-double%EC%9D%98-%EC%B0%A8%EC%9D%B4
    // 요점은 float의 최대값보다 double의 최대값이 더 크다는 것.
    int answer = 0;
    double cmp = 0;
    // 총점수가 높은 순으로, 인덱스가 낮은 순으로 정렬
    for(int i = 0; i < size; i++){
        if(p[i].second > cmp){
            answer = i;
            cmp = p[i].second;
        }
        else if(p[i].second == cmp){
            if(answer > p[i].first){
                answer = i;
                cmp = p[i].second;
            }
        } 
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //sort(p, p + size, cmp);
    //int answer = p[0].first;
    return answer;
}