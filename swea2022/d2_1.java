package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution_d2_1 {
	
	private final static int MAX_NODE = 10000;
	private final static int ADD_HEAD = 1;
	private final static int ADD_TAIL = 2;
	private final static int ADD_NUM = 3;
	private final static int REMOVE = 4;
	private final static int PRINT = 5;
	private final static int END = 99;
	
	private final static UserSolution_d2_1 usersolution = new UserSolution_d2_1();
	
	private static BufferedReader br;
	
	private static void run() throws Exception {
		
		int cmd, data, num, ret;
		int[] output = new int[MAX_NODE];
		String str;
		StringTokenizer st;
		
		while(true) {
			str = br.readLine();
			st = new StringTokenizer(str, " ");
			cmd = Integer.parseInt(st.nextToken());
			
			switch(cmd) {
			case ADD_HEAD :
				data = Integer.parseInt(st.nextToken());
				usersolution.addNode2Head(data);
				break;
				
			case ADD_TAIL :
				data = Integer.parseInt(st.nextToken());
				usersolution.addNode2Tail(data);
				break;
				
			case ADD_NUM :
				data = Integer.parseInt(st.nextToken());
				num = Integer.parseInt(st.nextToken());
				usersolution.addNode2Num(data, num);
				break;
				
			case REMOVE :
				data = Integer.parseInt(st.nextToken());
				usersolution.removeNode(data);
				break;
				
			case PRINT :
				ret = usersolution.getList(output);
				for(int i = 0; i < ret; i++) {
					System.out.print(output[i] + " ");
				}
				System.out.println();
				break;
				
			case END :
				return;
			}
		}
	}
	public static void main(String[] args) throws Exception {
		int TC;
		System.setIn(new java.io.FileInputStream("swea2022/sll_input.txt"));
		
		br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		TC = Integer.parseInt(str);
		
		for (int tc = 1; tc <= TC; tc++) {
			System.out.println("#" + tc);
			usersolution.init();
			run();
			System.out.println();
		}
	}

}

class Node_d2_1 {
	public int data;
	public Node_d2_1 next;

	public Node_d2_1(int data) {
		this.data = data;
		this.next = null;
	}
}

class UserSolution_d2_1 {

	private final static int MAX_NODE = 10000;

	private Node_d2_1[] node = new Node_d2_1[MAX_NODE];
	private int nodeCnt = 0;
    private Node_d2_1 head;
    
	public Node_d2_1 getNode(int data) {
		node[nodeCnt] = new Node_d2_1(data);
		return node[nodeCnt++];
	}

	public void init() {
        node = new Node_d2_1[MAX_NODE];
        head = new Node_d2_1(-1);
	}

	public void addNode2Head(int data) {
        Node_d2_1 node = getNode(data);
        node.next = head.next;
        head.next = node;
	}

	public void addNode2Tail(int data) {
        Node_d2_1 node = getNode(data);
        Node_d2_1 curr = head;
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.next = node;
	}

	public void addNode2Num(int data, int num) {
        Node_d2_1 node = getNode(data);
        Node_d2_1 curr = head;
        int cnt = 1;
        while (cnt != num) {
            curr = curr.next;
            cnt++;
        }
        node.next = curr.next;
        curr.next = node;
	}

	public void removeNode(int data) {
        Node_d2_1 curr = head.next;
        Node_d2_1 prev = head;
        while (curr != null) {
            if (curr.data == data) {
                break;
            } else {
                curr = curr.next;
                prev = prev.next;
            }
        }
        if (curr == null) return;
        prev.next = curr.next;
	}

	public int getList(int[] output) {
		Node_d2_1 curr = head.next;
        int idx = 0;
        while (curr != null) {
            output[idx] = curr.data;
            curr = curr.next;
            idx++;
        }
        return idx;
	}
}
