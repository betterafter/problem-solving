package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d5_2
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));

		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int n, p, max = 0;
            String[] input = br.readLine().split(" ");
            n = Integer.parseInt(input[0]);
            p = Integer.parseInt(input[1]);

            String[] dInput = br.readLine().split(" ");
            int[] days = new int[n];
            int[] visited = new int[1000100];
            for (int i = 0; i < n; i++) {
                days[i] = Integer.parseInt(dInput[i]);
                visited[days[i]] = 1;
            }

            max = p + 1;
            int res = 0;
            int left = 1;
            int right = 1;
            while (right < days[n - 1] + 1) {
                if (visited[right] == 1) {
                    res++;
                    right++;
                    max = Math.max(max, res);
                } else {
                    if (p == 0) {
                        max = Math.max(max, res);
                        if (visited[left] == 0) p++;
                        left++;
                        res--;
                    } else {
                        p--;
                        res++;
                        right++;
                    }
                }
            }

            
            bw.write("#" + test_case + " " + max + '\n');
 		}
        bw.flush();
	}
}