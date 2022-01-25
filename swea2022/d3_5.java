package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d3_5
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            String[] c = br.readLine().split(" ");
            int N = Integer.parseInt(c[0]);
            int K = Integer.parseInt(c[1]);
            int[][] dp = new int[N + 10][K + 10];
            int[] w = new int[N + 10];
            int[] val = new int[N + 10];
            int result = 0;

            for (int i = 1; i <= N; i++) {
                String[] in = br.readLine().split(" ");
                w[i] = Integer.parseInt(in[0]);
                val[i] = Integer.parseInt(in[1]);
            }

            // 탐색 중인 물건
            for (int i = 1; i <= N; i++) {
                // 탐색 중인 무게
                for (int j = 0; j <= K; j++) {
                    // 물건이 너무 크면
                    if (w[i] > j) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j - w[i]] + val[i], dp[i - 1][j]);
                    }  
                }
            }

            for (int i = 1; i <= K; i++) {
                result = Math.max(result, dp[N][i]);
            }

            bw.write("#" + test_case + " " + result + '\n');
 		}
        bw.flush();
	}
}