package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution_d2_2 {

	private final static int MAX_NODE = 10000;
	private final static int ADD_HEAD = 1;
	private final static int ADD_TAIL = 2;
	private final static int ADD_NUM = 3;
	private final static int FIND = 4;
	private final static int REMOVE = 5;
	private final static int PRINT = 6;
	private final static int PRINT_REVERSE = 7;
	private final static int END = 99;
	
	private final static UserSolution_d2_2 usersolution = new UserSolution_d2_2();
	
	private static BufferedReader br;
	
	public static void run() throws Exception {
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
				
			case FIND :
				data = Integer.parseInt(st.nextToken());
				num = usersolution.findNode(data);
				System.out.println(num);
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
			
			case PRINT_REVERSE :
				ret = usersolution.getReversedList(output);
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
		System.setIn(new java.io.FileInputStream("swea2022/dll_input.txt"));
		
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

class Node_d2_2 {
	public int data;
	public Node_d2_2 prev;
	public Node_d2_2 next;

	public Node_d2_2(int data) {
		this.data = data;
		this.prev = null;
		this.next = null;
	}
}

class UserSolution_d2_2 {
	
	private final static int MAX_NODE = 10000;

	private Node_d2_2[] nodes = new Node_d2_2[MAX_NODE];
	private int nodeCnt = 0;
	private Node_d2_2 head, tail;
    
	public Node_d2_2 getNode(int data) {
        if (nodes[nodeCnt] == null) {
            nodes[nodeCnt] = new Node_d2_2(data);
        } else {
            nodes[nodeCnt].data = data;
        }
		return nodes[nodeCnt++];
	}

    public UserSolution_d2_2() {
        while (nodeCnt < MAX_NODE) {
            getNode(-100);
        }
    }

	public void init() {
        nodeCnt = 0;
        head = getNode(-1);
        tail = getNode(-1);
        head.next = tail;
        tail.prev = head;
	}
	
	public void addNode2Head(int data) {
        Node_d2_2 node = getNode(data);
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
	}

	public void addNode2Tail(int data) {
        Node_d2_2 node = getNode(data);
        node.next = tail;
        node.prev = tail.prev;
        tail.prev.next = node;
        tail.prev = node;
	}

	public void addNode2Num(int data, int num) {
        Node_d2_2 node = getNode(data);
        Node_d2_2 curr = head;
        int cnt = 1;
        while (cnt != num) {
            curr = curr.next;
            cnt++;
        }
        node.next = curr.next;
        node.prev = curr;
        curr.next.prev = node;
        curr.next = node;
	}
	
	public int findNode(int data) {
		Node_d2_2 curr = head.next;
        int idx = 1;
        while (curr.data != tail.data) {
            if (curr.data == data) {
                break;
            } else {
                curr = curr.next;
                idx++;
            }
        }
        return idx;
	}
	
	public void removeNode(int data) {
        Node_d2_2 curr = head.next;
        Node_d2_2 prev = head;
        while (curr.data != tail.data) {
            if (curr.data == data) {
                break;
            } else {
                curr = curr.next;
                prev = prev.next;
            }
        }
        if (curr.data == tail.data) return;
        prev.next = curr.next;
        curr.next.prev = prev;
	}

	public int getList(int[] output) {
		Node_d2_2 curr = head.next;
        int idx = 0;
        while (curr.data != tail.data) {
            output[idx] = curr.data;
            curr = curr.next;
            idx++;
        }
        return idx;
	}
	
	public int getReversedList(int[] output) {
		Node_d2_2 curr = tail.prev;
        int idx = 0;
        while (curr.data != head.data) {
            output[idx] = curr.data;
            curr = curr.prev;
            idx++;
        }
        return idx;
	}
}