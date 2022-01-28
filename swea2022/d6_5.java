package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Node_d6_5 {
    int[] parent = new int[21];
    ArrayList<Integer> children = new ArrayList<>();
    int depth = 0;
}

class Solution_d6_5
{
    static Node_d6_5[] tree = new Node_d6_5[100001];

    static int dist(int i, int j) {
        int lca = lca(i, j);
        return tree[i].depth - tree[lca].depth + tree[j].depth - tree[lca].depth;
    }

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
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int curr = 1, prev = 0;
            long res = 0;
            int N = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");

            for (int i = 0; i <= 100000; i++) {
                tree[i] = new Node_d6_5();
            }

            for (int i = 0; i < N - 1; i++) {
                int parent = Integer.parseInt(input[i]);
                tree[i + 2].parent[0] = parent;
                tree[i + 2].depth = tree[parent].depth + 1;
                tree[parent].children.add(i + 2);
            }

            for (int i = 1; i < 21; i++) {
                for (int j = 1; j <= N; j++) {
                    tree[j].parent[i] = tree[tree[j].parent[i - 1]].parent[i - 1];
                }
            }

            ArrayList<Integer> queue = new ArrayList<>();
            for (int i = 0; i < tree[1].children.size(); i++) {
                queue.add(tree[1].children.get(i));
            }

            while (queue.size() != 0) {
                prev = curr;
                curr = queue.remove(0);
                res += dist(curr, prev);
                for (int i = 0; i < tree[curr].children.size(); i++) {
                    queue.add(tree[curr].children.get(i));
                }
            }
            
            System.out.println("#" + test_case + " " + res);
 		}
	}
}