package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d4_1_fail
{
    static void quickSort(int l, int r, int[] arr) {
        if (l >= r) return;
        int pl = l;
        int pr = r;
        int mid = (l + r) / 2;

        while (true) {
            while (pl < mid && arr[pl] <= arr[mid]){ pl++; }
            while (pr > mid && arr[pr] >= arr[mid]) { pr--; }
            if (pl == pr) break;

            int temp = arr[pl];
            arr[pl] = arr[pr];
            arr[pr] = temp;

            if (mid == pl) { mid = pr; } 
            else if (mid == pr) { mid = pl; }
        }
        quickSort(l, mid - 1, arr);
        quickSort(mid + 1, r, arr);
        return;
    }

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int N = Integer.parseInt(br.readLine());
            int[] A = new int[3400];
            for (int i = 0; i < N; i++) {
                A[i] = Integer.parseInt(br.readLine());
            }
            int M = Integer.parseInt(br.readLine());
            int[] B = new int[M];
            for (int i = 0; i < M; i++) {
                B[i] = Integer.parseInt(br.readLine());
            }

            quickSort(0, M - 1, B);

            int result = 0;
            // 새로 넣는 리스트의 0번부터 M번까지
            for (int i = 0; i < M; i++) {
                int[] li = new int[N + M + 1];
                int[] temp = new int[N + M + 1];
                // 0부터 j위치에 차례로 삽입해보기
                for (int j = 0; j <= N; j++) {
                    li[j] = B[i];
                    for (int k = 0; k < j; k++) {
                        li[k] = A[k];
                    }
                    for (int k = j; k < N; k++) {
                        li[k + 1] = A[k];
                    }
                    
                    int val = 0;
                    int[] dp = new int[N + M]; 
                    dp[0] = li[0];
                    dp[1] = li[1];
                    dp[2] = li[0] + li[2];
                    for (int k = 3; k < N + 1; k++) {
                        dp[k] = Math.max(dp[k - 3], dp[k - 2]) + li[k];
                        val = Math.max(val, dp[k]);
                    }

                    if (val >= result) {
                        result = val;
                        for (int k = 0; k < N + M + 1; k++) {
                            temp[k] = li[k];
                        }
                    }
                }
                A = temp;
                N++;
            }
            
            bw.write("#" + test_case + " " + result + '\n');
 		}
        bw.flush();
	}
}