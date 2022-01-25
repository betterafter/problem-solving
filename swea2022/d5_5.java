package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution_d5_5
{
    static int[] arr;
    static int[] sorted;
    static long res = 0;

    static void merge(int l, int m, int r) {
        int i, j, k;
        i = l; j = m + 1; k = l;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                sorted[k++] = arr[i++];
            } else {
                sorted[k++] = arr[j++];
                res += m - i + 1;
            }
        }

        if (i > m) {
            while (j <= r)
                sorted[k++] = arr[j++];
        }
        else {
            while (i <= m)
                sorted[k++] = arr[i++];
        }
    
        // 배열 복사
        for (i = l; i <= r; i++) {
            arr[i] = sorted[i];
        }
    }
    
    static void mergeSort(int l, int r) {
        int m;
        if (l < r) {
            m = (l + r) / 2;
            mergeSort(l, m);
            mergeSort(m + 1, r);
            merge(l, m, r);
        }
    }
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            res = 0;
            arr = new int[100011];
            sorted = new int[100011];
            int N = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");
            for (int i = 1; i <= N; i++) {
                arr[i] = Integer.parseInt(input[i - 1]);
            }

            mergeSort(1, N);
            System.out.println("#" + test_case + " " + res);
 		}
	}
}