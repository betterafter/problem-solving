
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#define FD double

using namespace std;

FD Answer;
FD rad, sp, ep, curr_x, curr_y;

void Upper(FD ob_lx, FD ob_rx, FD ob_y){
    
    Answer += (ob_y - rad) * 2 + M_PI * rad + ob_rx - ob_lx;
    curr_x = ob_rx + rad;
}

void Lower(FD ob_lx, FD ob_rx, FD ob_y, FD d){

    Answer += 2 * rad * (atan2(d, rad - ob_y)) + ob_rx - ob_lx;
    curr_x = ob_rx + d;
}

int main(int argc, char** argv)
{
    int T, test_case;

    setbuf(stdout, NULL);
    //cin >> T;
    scanf("%d", &T);
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        int n;
        cin >> rad >> sp >> ep;
        cin >> n;
        curr_x = sp; curr_y = rad;
        
        for(int i = 0; i < n; i++){
            FD lx, rx, y;
            cin >> lx >> rx >> y;
            
            if(y >= rad){
                
                //cout << Answer << '\n';
                
                Answer += lx - rad - curr_x;
                curr_x = lx - rad;
                
                Upper(lx, rx, y);
            }
            else if(y < rad){
                double d = sqrt(pow(rad, 2) - pow(rad - y, 2));
                
                Answer += lx - d - curr_x;
                curr_x = lx - d;
                
                Lower(lx, rx, y, d);
            }
        }
        
        Answer += ep - curr_x;
 
//        cout << "Case #" << test_case+1 << endl;
//        cout << Answer << endl;
        
        printf("Case #%d\n", test_case + 1);
        printf("%.10f\n", Answer);
    }
    
    return 0;
}
