package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d1_2
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
            int N = Integer.parseInt(input[0]);
            int M = Integer.parseInt(input[1]);
            if ((M & ((1 << N) - 1)) == (M & ((1 << N) - 1) | ((1 << N) - 1))) {
                bw.write("#" + test_case + " ON\n");
            } else {
                bw.write("#" + test_case + " OFF\n");
            }
		}
        bw.flush();
	}
}