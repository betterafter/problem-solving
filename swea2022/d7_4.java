package swea2022;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

class Pair<T, E> {
    Node first, second;
    public Pair(Node first, Node second) {
        this.first = first;
        this.second = second;
    }  
}

class Node {
    Node parent;
    HashMap<String, Node> map = new HashMap<>();
    String name;

    public Node() { }
    public Node(String name) {
        this.name = name;
    }
}

class UserSolution {

	private final static int NAME_MAXLEN	= 7;
	private final static int PATH_MAXLEN	= 1999;
    static Node[] nodes = new Node[100010];
    static int cnt = 0;
    Node root;

    static void mstrcpy(char[] dest, char[] src) {
		int i = 0;
		while (src[i] != '\0') {
			dest[i] = src[i];
			i++;
		}
		dest[i] = src[i];
	}

    static void mstrncpy(char[] dest, char[] src, int len) {
		for (int i = 0; i < len; i++) {
			dest[i] = src[i];
		}
		dest[len] = '\0';
	}

	void init(int n) {
        cnt = 0;
        root = getNode("");
	}

    Node getNode(String name) {
        if (nodes[cnt] == null) { 
            nodes[cnt] = new Node(name);
        } else {
            nodes[cnt].name = name;
            nodes[cnt].map.clear();
        }
        return nodes[cnt++];
    }

    Node findNode(char[] path) {
        try{
            String[] paths = new String(path).split("/");

            Node curr = root;
            for (int i = 1; i < paths.length - 1; i++) {
                curr = curr.map.get(paths[i] + '\0');
            }
            return curr;
        } catch (Exception e) { }
        return null;
    }

	void cmd_mkdir(char[] path, char[] name) {
        try {
            Node node = getNode(new String(name));
            Node curr = findNode(path);
            curr.map.put(new String(name), node);
            node.parent = curr;
            
        } catch (Exception e) { }
	}

	void cmd_rm(char[] path) {
        try {
            Node curr = findNode(path);
            curr.parent.map.remove(curr.name);
        } catch (Exception e) { } 
	}
	
	void cmd_cp(char[] srcPath, char[] dstPath) {
        try {
            Node n1 = findNode(srcPath);
            Node n2 = findNode(dstPath);

            Node cpy = cloneNode(n1);
            n2.map.put(new String(cpy.name), cpy);
            cpy.parent = n2;
        } catch (Exception e) { }
	}

    Node cloneNode(Node node) {
        try {
            Node result = getNode(new String(node.name));

            ArrayList<Pair<Node, Node> > queue = new ArrayList<>();
            queue.add(new Pair(node, result));
            while (!queue.isEmpty()) {
                Pair p = queue.remove(0);
                Node n1 = p.first;
                Node n2 = p.second;

                Iterator<String> keys = n1.map.keySet().iterator();
                while (keys.hasNext()) {
                    String key = keys.next();

                    Node cn = getNode(key);
                    cn.parent = n2;
                    n2.map.put(key, cn);
                    queue.add(new Pair(n1.map.get(key), cn));
                }
            }
            return result;
        } catch (Exception e) { }
        return null;
    }
	
	void cmd_mv(char[] srcPath, char[] dstPath) {
        try {
            Node n1 = findNode(srcPath);
            Node n2 = findNode(dstPath);

            n1.parent.map.remove(n1.name);
            n2.map.put(n1.name, n1);
            n1.parent = n2;
        } catch (Exception e) { }
	}
	
	int cmd_find(char[] path) {
        try {
            int cnt = 0;
            Node node = findNode(path);

            ArrayList<Node> queue = new ArrayList<>();
            queue.add(node);
            while (!queue.isEmpty()) {
                Node curr = queue.remove(0);

                Iterator<String> keys = curr.map.keySet().iterator();
                while (keys.hasNext()) {
                    String key = keys.next();
                    queue.add(curr.map.get(key));
                    cnt++;
                }
            }
            return cnt;
	    } catch (Exception e) { }
        return 0;
    } 
}


class Solution {

	private static UserSolution usersolution = new UserSolution();
	
	private final static int CMD_MKDIR		= 1;
	private final static int CMD_RM			= 2;
	private final static int CMD_CP			= 3;
	private final static int CMD_MV			= 4;
	private final static int CMD_FIND		= 5;
	
	private final static int NAME_MAXLEN	= 6;
	private final static int PATH_MAXLEN	= 1999;

	
	private static boolean run(Scanner sc, int m) throws Exception {

		boolean isAccepted = true;
		int cmd;
		char[] name;
		char[] path1;
		char[] path2;
		String inputStr = "";
        int cnt = 1;

		while (m-- > 0) {
			
			cmd = sc.nextInt();

			if (cmd == CMD_MKDIR) {
				inputStr = sc.next() + " ";
				path1 = inputStr.toCharArray();
				path1[inputStr.length() - 1] = '\0';
				inputStr = sc.next() + " ";
				name = inputStr.toCharArray();
				name[inputStr.length() - 1] = '\0';
				
				usersolution.cmd_mkdir(path1, name);
          
			}
			else if (cmd == CMD_RM) {
				inputStr = sc.next() + " ";
				path1 = inputStr.toCharArray();
				path1[inputStr.length() - 1] = '\0';
				
				usersolution.cmd_rm(path1);
          
			}
			else if (cmd == CMD_CP) {
				inputStr = sc.next() + " ";
				path1 = inputStr.toCharArray();
				path1[inputStr.length() - 1] = '\0';
				inputStr = sc.next() + " ";
				path2 = inputStr.toCharArray();
				path2[inputStr.length() - 1] = '\0';
				
				usersolution.cmd_cp(path1, path2);
       
			}
			else if (cmd == CMD_MV) {
				inputStr = sc.next() + " ";
				path1 = inputStr.toCharArray();
				path1[inputStr.length() - 1] = '\0';
				inputStr = sc.next() + " ";
				path2 = inputStr.toCharArray();
				path2[inputStr.length() - 1] = '\0';
				
				usersolution.cmd_mv(path1, path2);
                
			}
			else {
				int ret;
				int answer;

				inputStr = sc.next() + " ";
				path1 = inputStr.toCharArray();
				path1[inputStr.length() - 1] = '\0';
				
				ret = usersolution.cmd_find(path1);
				
				answer = sc.nextInt();

				isAccepted &= (ret == answer);
        
			}
		}

		return isAccepted;
	}
	
	public static void main(String[] args) throws Exception {
		int test, T;
		int n, m;

		System.setIn(new java.io.FileInputStream("swea2022/sample_sample_input.txt"));
		
		Scanner sc = new Scanner(System.in);
		
		T = sc.nextInt();
		
		for (test = 1; test <= T; ++test) {
			
			n = sc.nextInt();
			m = sc.nextInt();

			usersolution.init(n);

			if (run(sc, m)) {
				System.out.println("#" + test + " 100");
			}
			else {
				System.out.println("#" + test + " 0");
			}
		}
		
		sc.close();
	}
}