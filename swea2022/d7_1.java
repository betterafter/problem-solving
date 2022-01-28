package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Node_d7_1 {
    char data;
    int left = -1, right = -1;
}

class Solution_d7_1
{
    static Node_d7_1[] nodes = new Node_d7_1[110];
    static int[] parent = new int[110];
    static String res;

    static void inorder(Node_d7_1 node) {
        if (node.left != -1) inorder(nodes[node.left]);
        res += node.data;
        if (node.right != -1) inorder(nodes[node.right]);
    }
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
            res = "";
            int N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                int curr = Integer.parseInt(input[0]);
                char data = input[1].charAt(0);
                
                nodes[curr] = new Node_d7_1();
                nodes[curr].data = data;

                if (input.length >= 3) {
                    int left = Integer.parseInt(input[2]);
                    nodes[curr].left = left;
                    parent[left] = curr;
                }

                if (input.length >= 4) {
                    int right = Integer.parseInt(input[3]);
                    nodes[curr].right = right;
                    parent[right] = curr;
                }
            }

            inorder(nodes[1]);
            bw.write("#" + test_case + " " + res + '\n');
 		}
        bw.flush();
	}
}