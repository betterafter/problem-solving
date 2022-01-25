package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
class Solution_d5_4
{
    static int[] W = new int[200010];
    static int[] S = new int[200010];
    static int N, K;

    static boolean check(int mid) {
        int chunckIdx = 0;
        int piece = 0;

        for (int i = 0; i < N; i++) {
            // 덩어리 부속품이 mid 보다 작으면 덩어리를 계속 이어붙일 수 있음
            if (W[i] <= mid) {
                piece++;
                // 그렇지 않을 때 덩어리가 다 안끝날 경우 리셋
            } else {
                piece = 0;
            }

            if (piece == S[chunckIdx]) {
                chunckIdx++;
                piece = 0;
            }
            if (chunckIdx >= K) return true;
        }
        return false;
    }
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int res = 0;
            String[] input1 = br.readLine().split(" ");
            N = Integer.parseInt(input1[0]);
            K = Integer.parseInt(input1[1]);

            String[] input2 = br.readLine().split(" ");
            for (int i = 0; i < N; i++) {
                W[i] = Integer.parseInt(input2[i]);
            }

            String[] input3 = br.readLine().split(" ");
            for (int i = 0; i < K; i++) {
                S[i] = Integer.parseInt(input3[i]);
            }

            int left = 1;
            int right = 200000;
            while (left < right) {
                int mid = (left + right) / 2;
                if (check(mid)) {
                    right = mid;
                    res = right;
                } else {
                    left = mid + 1;
                }
            }

            System.out.println("#" + test_case + " " + res);
 		}
	}
}