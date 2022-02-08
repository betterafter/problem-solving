package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d9_2
{
    static int SIZE = 100010;
    static int[] pi = new int[SIZE];

    static void getPi(String str) {
        pi[0] = 0;
        for (int i = 1; i < str.length(); i++) {
            int j = pi[i - 1];
            while (j > 0 && str.charAt(i) != str.charAt(j)) {
                j = pi[j - 1];
            }

            if (str.charAt(i) == str.charAt(j)) pi[i] = j + 1;
            else pi[i] = 0;
        }
    }

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int ans = 0;
            String s1 = br.readLine();
            String s2 = br.readLine();
            getPi(s2);

            int idx = 0, cnt = 0;
            while (idx < s1.length()) {

                if (s1.charAt(idx) == s2.charAt(cnt)) {
                    if (cnt >= s2.length() - 1) {
                        ans++;
                        cnt = pi[cnt];
                    } else cnt++;
                    idx++;
                } else if (cnt > 0) cnt = pi[cnt - 1];
                else idx++;
            }

            System.out.println("#" + test_case + " " + ans);
 		}
        bw.flush();
	}
}