package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d1_1
{
	public static void main(String args[]) throws Exception
	{
        BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
        int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int N = Integer.parseInt(br.readLine());
            int check = 1 << 10;
            int i = 1;
			while (true) {
                String str = Integer.toString(N *  i);
                for (int j = 0; j < str.length(); j++) {
                    check = check | (1 << str.charAt(j) - '0');
                }
                if ((check & ((1 << 10) - 1)) == (1 << 10) - 1) {
                    bw.write("#" + test_case + " " + (i * N) + '\n');
                    break;
                }
                i++;
            }
		}
        bw.flush();
	}
}