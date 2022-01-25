package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Node_d2_3 {
    public int data;
    public Node_d2_3 prev;
    public Node_d2_3 next;

    public Node_d2_3(int data) {
        this.data = data;
    }
}

class UserSolution_d2_3 {
    int MAX_NODE = 2000000;
    Node_d2_3[] nodes = new Node_d2_3[MAX_NODE];
    int nodeCnt = 0;
    Node_d2_3 head, tail;

    public void init() {
        nodeCnt = 0;
        head = getNode(-1);
        tail = getNode(-1);
        head.next = tail;
        tail.prev = head;
    }

    public Node_d2_3 getNode(int data) {
        if (nodes[nodeCnt] == null) {
            nodes[nodeCnt] = new Node_d2_3(data);
        } else {
            nodes[nodeCnt].data = data;
        }
        return nodes[nodeCnt++];
    }

    public void insert(int x, int num, int[] nums) {
        Node_d2_3 curr = head;
        for (int i = 0; i < x; i++) {
            curr = curr.next;
        }
        
        for (int i = 0; i < nums.length; i++) {
            Node_d2_3 node = getNode(nums[i]);
            node.prev = curr;
            node.next = curr.next;
            curr.next.prev = node;
            curr.next = node;
            curr = node;
        }
    }

    public void delete(int x, int num) {
        Node_d2_3 curr = head;
        for (int i = 0; i < x; i++) {
            curr = curr.next;
        }
        for (int i = 0; i < num; i++) {
            curr.next.next.prev = curr;
            curr.next = curr.next.next;
        }
    }

    public void add(int num, int[] nums) {
        Node_d2_3 curr = tail.prev;
        for (int i = 0; i < nums.length; i++) {
            Node_d2_3 node = getNode(nums[i]);
            node.prev = curr;
            node.next = curr.next;
            curr.next.prev = node;
            curr.next = node;
            curr = node;
        }
    }

    public void attach(int data) {
        Node_d2_3 node = getNode(data);
        node.prev = tail.prev;
        node.next = tail;
        tail.prev.next = node;
        tail.prev = node;
    }

    public int[] print() {
        Node_d2_3 curr = head.next;
        int[] result = new int[10];
        for (int i = 0; i < 10; i++) {
            result[i] = curr.data;
            curr = curr.next;
        }
        return result;
    }
}

class Solution_d2_3
{
	public static void main(String args[]) throws Exception
	{
        UserSolution_d2_3 userSolution = new UserSolution_d2_3();
        //System.setIn(new java.io.FileInputStream("swea2022/input.txt"));
        BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
        int T;
		T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
            userSolution.init();
            int N = Integer.parseInt(br.readLine());
            String[] crypt = br.readLine().split(" ");
            int ON = Integer.parseInt(br.readLine());
            String[] order = br.readLine().split(" ");

            for (int i = 0; i < N; i++) {
                userSolution.attach(Integer.parseInt(crypt[i]));
            }

            int idx = 0;
            int x, num;
            int nums[];
            while (idx < order.length) {
                switch(order[idx++]) {
                    case "I" :
                        x = Integer.parseInt(order[idx++]);
                        num = Integer.parseInt(order[idx++]);
                        nums = new int[num];
                        for (int i = 0; i < num; i++) {
                            nums[i] = Integer.parseInt(order[idx++]);
                        }
                        userSolution.insert(x, num, nums);
                        break;
                    case "D" :
                        x = Integer.parseInt(order[idx++]);
                        num = Integer.parseInt(order[idx++]);
                        userSolution.delete(x, num);
                        break;
                    case "A" :
                        num = Integer.parseInt(order[idx++]);
                        nums = new int[num];
                        for (int i = 0; i < num; i++) {
                            nums[i] = Integer.parseInt(order[idx++]);
                        }
                        userSolution.add(num, nums);
                        break;
                }
            }

            int[] result = userSolution.print();
            System.out.printf("#" + test_case + " ");
            for (int i = 0; i < 10; i++) {
                System.out.printf(result[i] + " ");
            }
            System.out.println("");
		}
        bw.flush();
	}
}