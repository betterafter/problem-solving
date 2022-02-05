package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;

class Node implements Comparable<Node> {
    long a, b;
    public Node(long a, long b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public int compareTo(Node o) {
        if (a < o.a) return -1;
        else if (a == o.a) return 0;
        else return 1;
    }
        
}

class Solution
{
    static long[] num = new long[11];
    static PriorityQueue<Node> pq = new PriorityQueue<>();
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            long K;

            int N = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");

            for (int i = 0; i < N; i++) {
                num[i] = Long.parseLong(input[i]);
            }

            K = Long.parseLong(br.readLine());
            pq.add(new Node(0, K));

            while (!pq.isEmpty()) {

                if (pq.peek().b == 0) break;
                Node curr = pq.poll();
                long a = curr.a;
                long b = curr.b;

                pq.add(new Node(a + b, 0));
                for (int i = 0; i < N; i++) {
                    pq.add(new Node(a + b % num[i], b / num[i]));
                }
            }

            bw.write("#" + test_case + " " + pq.peek().a + '\n');
            pq.clear();
        }
        bw.flush();
	}
}