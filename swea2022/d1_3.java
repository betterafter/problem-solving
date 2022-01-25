package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d1_3
{
	public static void main(String args[]) throws Exception
	{
        BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
        int T;
        int DIV = 1000000007;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int result = 0;
            String order = br.readLine();
            int[][] day = new int[order.length()][16];

            for (int i = 0; i < order.length(); i++) {
                // manager 찾기 : order.charAt(i) - 'A' 가 0 ~ 3까지 나올 것임.
                // 예시 - manager = 0100(B) 이면
                int manager = 1 << (order.charAt(i) - 'A');
                // 16가지 경우 모두 체크
                for (int j = 0; j < 16; j++) {
                    // 첫번째 날이면
                    if (i == 0) {
                        // 0000 ~ 1111까지 0100(B)랑 & 연산을 적용해서 0이 아닌지 체크, 즉 x1xx 꼴인 값인지 체크
                        // 조건에 첫째날에는 A가 열쇠를 가지고 있음. 따라서 x1x1 꼴이 나와야 함.
                        if ((j & manager) != 0 && (j & 1) != 0) {
                            day[i][j] = 1;
                        }
                    } else {
                        // 어제 있었던 경우를 체크
                        if (day[i - 1][j] != 0) {
                            for (int k = 0; k < 16; k++) {
                                if ((k & j) != 0 && (manager & k) != 0) {
                                    day[i][k] = (day[i - 1][j] + day[i][k]) % DIV;
                                }
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < 16; i++) {
                result = (result + day[order.length() - 1][i]) % DIV;
            }
            System.out.println("#" + test_case + " " + result);
		}
        bw.flush();
	}
}

/*
참고 
            _ 1 _ _     ->      _ _ 1 _ 로 가는 경우
            0 1 0 0     ->      0 1 1 0
1 0 0 0 <-  1 1 0 0     ->      1 0 1 0, 0 1 1 0, 1 1 1 0
0 1 0 0     0 1 1 0     ->      0 1 1 0, 0 0 1 0
1 1 0 0     0 1 0 1     ->      0 1 1 0, 0 0 1 1, 0 1 1 1
도출         1 1 1 0     ...
            1 1 0 1     ...
            1 1 1 1     ...

// 위에서 1 0 0 0, 0 1 0 0, 1 1 0 0을 도출하는 방법은
// 0 ~ 15 (0 0 0 0 ~ 1 1 1 1)과 1 1 0 0을 & 해서 0이 아닌 것을 뽑아내면 된다. 
// 예를 들어 1 0 0 0 & 1 1 0 0 = 1 0 0 0 != 0인 식. 

예를 들어 이전 날의 1 1 0 0 의 경우 다음 날에 나올 수 있는 경우는 1 0 1 0, 0 1 1 0, 1 1 1 0이 될 것임. 
(A,C가 참가하거나, B,C가 참가하거나, A,B,C가 참가하거나)

즉 이전 날인 1 1 0 0 에서 다음 날에도 참가하는 경우를 구하면 1 0 0 0, 0 1 0 0, 1 1 0 0 이 나옴.
이것을 다음 날의 매니저 필수 조건인 (0 0 1 0) 과 & 해야 다음 날의 경우의 수가 나올 것.
이렇게 나온 경우의 수를 다음 날로 계속 누적해서 구하는 것임.
*/


