package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d3_1
{
	public static void main(String args[]) throws Exception
	{
		
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		int[] money = new int[] {
            50000, 10000, 5000, 1000, 500, 100, 50, 10
        };

		for(int test_case = 1; test_case <= T; test_case++)
		{
            int N = Integer.parseInt(br.readLine());
            int[] result = new int[money.length];
            for (int i = 0; i < money.length; i++) {
                result[i] = N / money[i];
                N = N % money[i];
            }
            bw.write("#" + test_case + '\n');
            for (int i = 0; i < money.length; i++) {
                bw.write(result[i] + " ");
            }
            bw.write('\n');
            bw.flush();
 		}
	}
}