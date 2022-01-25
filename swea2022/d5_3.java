package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Solution_d5_3
{
    static boolean[] peeks = new boolean[100000000];
    static int L, N, start, end, max;
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            L = Integer.parseInt(br.readLine());
            N = Integer.parseInt(br.readLine());

            start = 0;
            end = 0;
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                start = Integer.parseInt(input[0]);
                end = Integer.parseInt(input[1]);
                for (int j = start; j < end; j++) {
                    peeks[j] = true;
                }
            }

            max = 0;
            for (int i = 0; i < L; i++) {
                max += peeks[i] ? 1 : 0;
            }

            int left = 0;
            int right = L;
            int sum = max;
            while (right < end) {
                max += peeks[right++] ? 1 : 0;
                max -= peeks[left++] ? 1 : 0;
                sum = Math.max(max, sum);
            }
            System.out.println("#" + test_case + " " + sum);
            Arrays.fill(peeks, false);
 		}
	}
}