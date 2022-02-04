package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d8_2
{
    private static int MAX = 100001;
    static long[] heap = new long[MAX];
    static int size = 1;

    static void push(long value) {
        heap[size] = value;

        int curr = size;
        while (curr > 1) {
            int parent = curr / 2;
            if (heap[parent] > heap[curr]) break;
            long temp = heap[parent];
            heap[parent] = heap[curr];
            heap[curr] = temp;

            curr = parent;
        }

        size++;
    }

    static long pop() {
        if (size <= 1) return -1;

        long val = heap[1];
        size = size - 1;
        heap[1] = heap[size];

        int curr = 1;
        while (curr * 2 < size) {
            int child;

            if (curr * 2 + 1 == size) child = curr * 2;
            else child = heap[curr * 2] > heap[curr * 2 + 1] ? curr * 2 : curr * 2 + 1;
            if (heap[curr] > heap[child]) break;

            long temp = heap[curr];
            heap[curr] = heap[child];
            heap[child] = temp;
            
            curr = child;
        }

        return val;
    }
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            size = 1;

            int N = Integer.parseInt(br.readLine());
            System.out.printf("#" + test_case + " ");
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                if (input.length == 2) {
                    long val = Long.parseLong(input[1]);
                    push(val);
                } else {
                    long val = pop();
                    System.out.printf(val + " ");
                }
            }

            System.out.println("");
 		}
        bw.flush();
	}
}