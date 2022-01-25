package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d3_4
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            String[] input = br.readLine().split(" ");
            int[][] dp = new int[input[0].length() + 10][input[1].length() + 10];

            for (int i = 0; i < input[0].length(); i++) {
                for (int j = 0; j < input[1].length(); j++) {
                    if (input[0].charAt(i) == input[1].charAt(j)) {
                        dp[i + 1][j + 1] = dp[i][j] + 1;
                    } else {
                        dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
                    }
                }
            }

            // for (int i = 0; i < input[0].length() + 5; i++) {
            //     for (int j = 0; j < input[1].length() + 5; j++) {
            //         System.out.printf(dp[i][j] + " ");
            //     }
            //     System.out.println(" ");
            // }

            bw.write("#" + test_case + " " + dp[input[0].length()][input[1].length()] + '\n');
 		}
        bw.flush();
	}
}