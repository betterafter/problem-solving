#include <string>
#include <vector>

using namespace std;

char m[6][6];

bool corona(){

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(m[i][j] == 'P'){
                if( 
                (i + 1 < 5 && m[i + 1][j] == 'P') ||
                (j + 1 < 5 && m[i][j + 1] == 'P') ||
                (i - 1 < 5 && m[i - 1][j] == 'P') || 
                (j - 1 < 5 && m[i][j - 1] == 'P')
                ){
                    return false;
                }


                if(i + 2 < 5 && m[i + 2][j] == 'P'){
                    if(m[i + 1][j] == 'O') return false;
                }

                if(j + 2 < 5 && m[i][j + 2] == 'P'){
                    if(m[i][j + 1] == 'O') return false;
                }

                if(i - 2 < 5 && m[i - 2][j] == 'P'){
                    if(m[i - 1][j] == 'O') return false;
                }

                if(j - 2 < 5 && m[i][j - 2] == 'P'){
                    if(m[i][j - 1] == 'O') return false;
                }



                if(i + 1 < 5 && j + 1 < 5 && m[i + 1][j + 1] == 'P'){
                    if(m[i + 1][j] == 'O' || m[i][j + 1] == 'O') return false;
                }

                if(i + 1 < 5 && j - 1 < 5 && m[i + 1][j - 1] == 'P'){
                    if(m[i + 1][j] == 'O' || m[i][j - 1] == 'O') return false;
                }

                if(i - 1 < 5 && j + 1 < 5 && m[i - 1][j + 1] == 'P'){
                    if(m[i - 1][j] == 'O' || m[i][j + 1] == 'O') return false;
                }

                if(i - 1 < 5 && j - 1 < 5 && m[i - 1][j - 1] == 'P'){
                    if(m[i - 1][j] == 'O' || m[i][j - 1] == 'O') return false;
                }   

            }
        }
    }

    return true;
}


vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;

    for(int i = 0; i < places.size(); i++){


        for(int j = 0; j < places[i].size(); j++){
            for(int k = 0; k < places[i][j].size(); k++){
                m[j][k] = places[i][j][k];
            }
        }

        if(corona()) answer.push_back(1);
        else answer.push_back(0);
    }


    return answer;
}