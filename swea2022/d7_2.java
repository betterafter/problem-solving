package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Node_d7_2 {
    String data;
    int left = -1, right = -1;
}

class Solution_d7_2
{
    static Node_d7_2[] nodes = new Node_d7_2[1100];
    static int[] parent = new int[1100];
    static String res;
    static boolean check;

    static String inorder(Node_d7_2 node) {
        String left = "", right = "", op;
        try {
            if (node.left != -1) left = inorder(nodes[node.left]);
            op = node.data;
            if (node.right != -1) right = inorder(nodes[node.right]);
            if (node.left == -1 && node.right == -1) return node.data;
            //System.out.println(left + " (no : " + node.left + ")" + " , " + right + "(no : " + node.right + ")");
            if (op.compareTo("+") == 0) return Long.toString(Long.parseLong(left) + Long.parseLong(right));
            if (op.compareTo("-") == 0) return Long.toString(Long.parseLong(left) - Integer.parseInt(right));
            if (op.compareTo("*") == 0) return Long.toString(Long.parseLong(left) * Long.parseLong(right));
            if (op.compareTo("/") == 0) { 
                if (Long.parseLong(right) == 0) return Long.toString(Long.parseLong(left) / 1);
                return Long.toString(Long.parseLong(left) / Long.parseLong(right));
            }
        } catch (Exception e) {
            return "";
        }
        return "";
    }
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                int curr = Integer.parseInt(input[0]);
                String data = input[1];
                
                nodes[curr] = new Node_d7_2();
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

            bw.write("#" + test_case + " " + (int)Math.floor(Double.parseDouble(inorder(nodes[1]))) + '\n');
 		}
        bw.flush();
	}
}