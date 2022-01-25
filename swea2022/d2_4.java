package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Node_d2_4 {
    public int data;
    public Node_d2_4 prev;
    public Node_d2_4 next;

    public Node_d2_4(int data) {
        this.data = data;
    }
}

class UserSolution_d2_4 {
    int MAX_NODE = 100000;
    Node_d2_4[] nodes = new Node_d2_4[MAX_NODE];
    int nodeCnt = 0;
    Node_d2_4 head, tail;

    public void init() {
        nodeCnt = 0;
        head = getNode(-1);
        tail = getNode(-1);
        head.next = tail;
        tail.prev = head;
    }

    public Node_d2_4 getNode(int data) {
        if (nodes[nodeCnt] == null) {
            nodes[nodeCnt] = new Node_d2_4(data);
        } else {
            nodes[nodeCnt].data = data;
        }
        return nodes[nodeCnt++];
    }

    public void insert(int pos, int data) {
        Node_d2_4 node = getNode(data);
        Node_d2_4 curr = head.next;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }
        node.prev = curr.prev;
        node.next = curr;
        curr.prev.next = node;
        curr.prev = node;
    }

    public void delete(int pos) {
        Node_d2_4 curr = head.next;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }
        curr.prev.next = curr.next;
        curr.next.prev = curr.prev;
    }

    public void change(int pos, int data) {
        Node_d2_4 curr = head.next;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }
        curr.data = data;
    }

    public void attach(int data) {
        Node_d2_4 node = getNode(data);
        node.prev = tail.prev;
        node.next = tail;
        tail.prev.next = node;
        tail.prev = node;
    }

    public int print(int pos) {
        Node_d2_4 curr = head.next;
        // 이 줄을 빼먹으면
        if (curr.data == -1) return -1;
        /*
        1
        5 5 1
        1 2 3 4 5
        D 0
        D 0
        D 0
        D 0
        D 0
        에 대하여 런타임 에러 발생
        */
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
            if (curr.data == -1) return -1;
        }
        return curr.data;
    }
}

class Solution_d2_4
{
	public static void main(String args[]) throws Exception
	{
        UserSolution_d2_4 userSolution = new UserSolution_d2_4();
        //System.setIn(new java.io.FileInputStream("swea2022/input.txt"));
        BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
        int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            userSolution.init();
            String[] input = br.readLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int M = Integer.parseInt(input[1]);
            int L = Integer.parseInt(input[2]);
            String[] arr = br.readLine().split(" ");
            for (int i = 0; i < N; i++) {
                userSolution.attach(Integer.parseInt(arr[i]));
            }

            for (int i = 0; i < M; i++) {
                String[] order = br.readLine().split(" ");
                switch(order[0]) {
                    case "I" :
                        userSolution.insert(Integer.parseInt(order[1]), Integer.parseInt(order[2]));
                        break;
                    case "D" :
                        userSolution.delete(Integer.parseInt(order[1]));
                        break;
                    case "C" :
                        userSolution.change(Integer.parseInt(order[1]), Integer.parseInt(order[2]));
                        break;
                }
            }

            System.out.printf("#" + test_case + " ");
            System.out.printf(userSolution.print(L) + " ");
            System.out.println("");
		}
        bw.flush();
	}
}