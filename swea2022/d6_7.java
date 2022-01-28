package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;

class Node_d6_7 implements Comparable<Node_d6_7> {
    int from, to;
    long val;

    public Node_d6_7(int from, int to, long val) {
        this.from = from;
        this.to = to;
        this.val = val;
    }
    
    @Override
    public int compareTo(Node_d6_7 o) {
        if (this.val < o.val) return -1;
        else if (this.val > o.val) return 1;
        else return 0;
    }
}

class Solution_d6_7
{
    static ArrayList<Node_d6_7> nodes;
    static int[] parent = new int[50010];

    static int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    static void merge(int u, int v){
        u = find(u);
        v = find(v);
        parent[u] = v;
    }
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            nodes = new ArrayList<>();
            int N = Integer.parseInt(br.readLine());
            int M = Integer.parseInt(br.readLine());

            for (int i = 0; i < M; i++) {
                String[] input = br.readLine().split(" ");
                int s = Integer.parseInt(input[0]);
                int e = Integer.parseInt(input[1]);
                long c = Long.parseLong(input[2]);
                nodes.add(new Node_d6_7(s, e, c));
            }

            for (int i = 0; i <= N; i++) {
                parent[i] = i;
            }

            Collections.sort(nodes);

            long res = 0;
            for (int i = 0; i < nodes.size(); i++) {
                if(find(nodes.get(i).from) != find(nodes.get(i).to)){
                    merge(nodes.get(i).from, nodes.get(i).to);
                    res += nodes.get(i).val;
                }
            }

            bw.write("#" + test_case + " " + res + '\n');
 		}
        bw.flush();
	}
}