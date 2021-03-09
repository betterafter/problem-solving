//
//  RockFestival.c
//  APSS
//
//  Created by 신기열 on 08/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>

double lessValue(double a, double b){
    return (a < b) ? a : b;
}

int main(){

    int C;

    scanf("%d", &C);

    for(int i = 0; i < C; i++){

        // N : 공연 날 수, L : 공연 팀의 수 (공연 날 수의 최소)
        int Buffer[1001], N, L, count;
        double sum, result = 2e9;
        scanf("%d %d", &N, &L);
        //cin >> N >> L;

        for(int p = 0; p < N; p++){
            scanf("%d", &Buffer[p]);
            //cin >> Buffer[p];
        }

        ////////////case1
        for(int i = 0; i <= N - L; i++){

            sum = 0;
            count = 0;
            //최소까지 더한거

            for(int j = i; j < L + i; j++){
                sum += Buffer[j];
                count++;
            }

            result = lessValue(sum / count, result);
            printf("%.10lf\n", sum / L);
            for(int k = L + i; k < N; k++){

                sum = sum + Buffer[k];
                count++;
                result = lessValue(sum / count, result);
                printf("%.10lf\n", sum / count);
            }
        }

        printf("%.10lf\n", result);
    }


    return 0;
}
