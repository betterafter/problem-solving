package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d5_1
{
    static void merge(int l, int m, int r, String[] A, String[] sorted) {
        int i, j, k;
        i = l; j = m + 1; k = l;
        while (i <= m && j <= r) {
            if (A[i].length() < A[j].length()) {
                sorted[k++] = A[i++];
            } else if (A[i].length() > A[j].length()) {
                sorted[k++] = A[j++];
            } else {
                if (A[i].compareTo(A[j]) <= 0) {
                    sorted[k++] = A[i++];
                } else if (A[i].compareTo(A[j]) > 0) {
                    sorted[k++] = A[j++];
                }
            }
        }
    
        // 남아있는 값들 일괄 복사
        if (i > m) {
            while (j <= r)
                sorted[k++] = A[j++];
        }
        else {
            while (i <= m)
                sorted[k++] = A[i++];
        }
    
        // 배열 복사
        for (i = l; i <= r; i++) {
            A[i] = sorted[i];
        }
    }
    
    static void mergeSort(int l, int r, String[] A, String[] sorted) {
        int m;
        if (l < r) {
            m = (l + r) / 2;
            mergeSort(l, m, A, sorted);
            mergeSort(m + 1, r, A, sorted);
            merge(l, m, r, A, sorted);
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
            int N = Integer.parseInt(br.readLine());
            String[] A = new String[N];
            String[] sorted = new String[N];
            for (int i = 0; i < N; i++) {
                A[i] = br.readLine();
            }
            mergeSort(0, N - 1, A, sorted);

            bw.write("#" + test_case + '\n');
            for (int i = 0; i < N; i++) {
                if (i - 1 >= 0 && sorted[i - 1].compareTo(sorted[i]) == 0) continue;
                bw.write(sorted[i] + '\n');
            }
 		}
        bw.flush();
	}
}