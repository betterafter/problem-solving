package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Node_d9_1 {
    String key;
    Node_d9_1 next;

    Node_d9_1 alloc(String key, Node_d9_1 next) {
        this.key = key;
        this.next = next;
        return this;
    }

    Node_d9_1 getPrevNode(String _key) {
        Node_d9_1 curr = this;
        while (curr != null) {
            if (curr.key.compareTo(_key) == 0) break;
            curr = curr.next;
        }
        return curr;
    }
}

class Solution_d9_1
{
    static long SIZE = 1 << 18, MAXN = 100001, DIV = SIZE - 1;
    static Node_d9_1[] table = new Node_d9_1[(int)SIZE];
    static Node_d9_1[] buf = new Node_d9_1[(int)MAXN];
    static int bCnt = 0;

    static boolean compareTo(String a, String b) {
        if (a.length() != b.length()) return false;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) return false;
        }
        return true;
    }

    static void init() {
        bCnt = 0;
        for (int i = 0; i < SIZE; ++i) {
            table[i] = null;
        }

        for (int i = 0; i < MAXN; i++) {
            buf[i] = new Node_d9_1();
        }
    }

    static int getKey(String key) {
        long temp = 5381;
        for (int i = 0; i < key.length(); i++) {
            temp = (temp << 5) + temp + (key.charAt(i) - 'a' + 1);
        }
        return (int)(temp & DIV);
    }

    static void add(String key) {
        int target = getKey(key);
        table[target] = buf[bCnt++].alloc(key, table[target]);
    }

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int ans = 0;
            init();
            String[] in = br.readLine().split(" ");
            String[] str1 = br.readLine().split(" ");
            String[] str2 = br.readLine().split(" ");
            for (int i = 0; i < Integer.parseInt(in[0]); i++) {
                add(str1[i]);
            }

            for (int i = 0; i < Integer.parseInt(in[1]); i++) {
                int hash = getKey(str2[i]);
                Node_d9_1 node = table[hash];
                while(node != null) {
                    if(compareTo(node.key, str2[i]) ) {
                        ans++;
                        break;
                    } else node = node.next;
                }
            }
            bw.write("#" + test_case + " " + ans + '\n');
 		}
        bw.flush();
	}
}