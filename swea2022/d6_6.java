package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;

class Node_d6_6 implements Comparable<Node_d6_6> {
    int from;
    int to;
    long val;
    public Node_d6_6(int from, int to, long val) {
        this.from = from;
        this.to = to;
        this.val = val;
    }

    @Override
    public int compareTo(Node_d6_6 o) {
        if (this.val < o.val) return -1;
        else return 1;
    }
}

class Solution_d6_6
{
    static int[] parent = new int[1010];
    static ArrayList<Node_d6_6> edges = new ArrayList<>();

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
            edges = new ArrayList<>();
            int N = Integer.parseInt(br.readLine());
            String[] xs = br.readLine().split(" ");
            String[] ys = br.readLine().split(" ");
            double E = Double.parseDouble(br.readLine());

            for (int i = 0; i < N; i++) {
                parent[i] = i;
            }

            for (int i = 0; i < N - 1; i++) {
                long x = Long.parseLong(xs[i]);
                long y = Long.parseLong(ys[i]);
                for (int j = i + 1; j < N; j++) {
                    long nx = Long.parseLong(xs[j]);
                    long ny = Long.parseLong(ys[j]);
                    long val = (x - nx) * (x - nx) + (y - ny) * (y - ny);
                    edges.add(new Node_d6_6(i, j, val));
                }
            }
            
            Collections.sort(edges);

            long res = 0;
            for (int i = 0; i < edges.size(); i++) {
                if(find(edges.get(i).from) != find(edges.get(i).to)){
                    merge(edges.get(i).from, edges.get(i).to);
                    res += edges.get(i).val;
                }
            }

            bw.write("#" + test_case + " " + Math.round(res * E) + '\n');
 		}
        bw.flush();
	}
}