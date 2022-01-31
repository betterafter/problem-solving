package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

class Node_d7_3 {
    int[] parent = new int[21];
    ArrayList<Integer> children = new ArrayList<>();
    int depth = 0;
}

class Solution_d7_3
{
    static Node_d7_3[] tree = new Node_d7_3[100001];

    static int lca(int i, int j) {
        if (tree[i].depth > tree[j].depth) {
            int temp = j;
            j = i;
            i = temp;
        }
        for (int n = 20; n >= 0; n--) {
            if (tree[j].depth - tree[i].depth >= (1 << n)) {
                j = tree[j].parent[n];
            }
        }
        if (i == j) return i;

        for (int n = 20; n >= 0; n--) {
            if (tree[i].parent[n] != tree[j].parent[n]) {
                i = tree[i].parent[n];
                j = tree[j].parent[n];
            }
        }

        return tree[i].parent[0];
    }
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int V, E, n1, n2;
            String[] input = br.readLine().split(" ");
            V = Integer.parseInt(input[0]);
            E = Integer.parseInt(input[1]);
            n1 = Integer.parseInt(input[2]);
            n2 = Integer.parseInt(input[3]);

            for (int i = 0; i <= V; i++) {
                tree[i] = new Node_d7_3();
            }

            String[] input2 = br.readLine().split(" ");
            for (int i = 0; i < E * 2; i += 2) {
                int parent = Integer.parseInt(input2[i]);
                int child = Integer.parseInt(input2[i + 1]);
                tree[child].parent[0] = parent;
                tree[parent].children.add(child);
            }

            ArrayList<Integer> queue = new ArrayList<>();
            queue.add(1);
            tree[1].depth = 0;
            while (queue.size() > 0) {
                int curr = queue.remove(0);
                int depth = tree[curr].depth;
                for (int i = 0; i < tree[curr].children.size(); i++) {
                    queue.add(tree[curr].children.get(i));
                    tree[tree[curr].children.get(i)].depth = depth + 1;
                }
            }

            for (int i = 1; i < 21; i++) {
                for (int j = 1; j <= V; j++) {
                    tree[j].parent[i] = tree[tree[j].parent[i - 1]].parent[i - 1];
                }
            }

            int parent = lca(n1, n2);
            int res = 1;
            queue.add(parent);
            while (queue.size() > 0) {
                int curr = queue.remove(0);
                for (int i = 0; i < tree[curr].children.size(); i++) {
                    queue.add(tree[curr].children.get(i));
                    res++;
                }
            }

            bw.write("#" + test_case + " " + parent + " " + res + '\n');
 		}
        bw.flush();
	}
}