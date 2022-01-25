package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d3_2
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int[] room = new int[210];
            int result = 0;
            int N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                int in = Integer.parseInt(input[0]);
                int out =Integer.parseInt(input[1]);
                if (in % 2 == 1) in++;
                if (out % 2 == 1) out++;
                in /= 2;
                out /= 2;
                for (int j = Math.min(in, out); j <= Math.max(in, out); j++) {
                    room[j]++;
                }
            }

            for (int i = 0; i <= 200; i++) {
                result = Math.max(result, room[i]);
            }

            bw.write("#" + test_case + " " + result + '\n');
 		}
        bw.flush();
	}
}