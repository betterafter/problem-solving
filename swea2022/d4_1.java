package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d4_1
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

            int[][][] dp = new int[3010][110][110];

            for (int i = 0; i < N + M; i++) {
                for (int p = 0; p < M; p++) {
                    
                }
            }

            
            //bw.write("#" + test_case + " " + result + '\n');
 		}
        bw.flush();
	}
}