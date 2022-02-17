package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class UserSolution_d13 {

	int L, M, currTime;
	PriorityQueue<Request> requests = new PriorityQueue<>();
	ArrayList<Product>[] products = new ArrayList[501];
	Line[] lines = new Line[501];
	boolean[] equips = new boolean[501];
	HashMap<Integer, Integer> st = new HashMap<>();

	class Line {
		int pid, currProductId;
		boolean isUsed;
		ArrayList<Product> products = new ArrayList<>();
	}

	class Product {
		int pId, eId, lId, mTime;
		
        public Product(int pId, int lId, int eId, int mTime) {
            this.pId = pId;
			this.lId = lId;
            this.eId = eId;
            this.mTime = mTime;
        }

		public Product(int pid) { 
			this.pId = pid;
		}
	}

    class Request implements Comparable<Request> {
        int time;
		Product product;
		public Request(int time, Product product) {
			this.time = time;
			this.product = product;
		}

        @Override
        public int compareTo(Request o) {
            if (this.time < o.time) return -1;
            else if (this.time == o.time) return 0;
            return 1;
        }
    }

	void init(int L, int M) {
		this.L = L; this.M = M;
		currTime = 0;
		requests.clear();
		st.clear();

        for (int i = 0; i < M; i++) {
            if (products[i] == null) products[i] = new ArrayList<>();
            else products[i].clear();

			equips[i] = false;
        }

        for (int i = 0; i < L; i++) {
            lines[i] = new Line();
        }
	}

	void timeFlow(int t) {
		while (!requests.isEmpty()) {
			Request request = requests.peek();
			if (request.time > t) break;

			currTime = request.time;
			while (!requests.isEmpty()) {
				Request re = requests.peek();
				if (re.time != currTime) break;
				requests.poll();

				if (re.product.pId < 0) continue;
				lines[re.product.lId].isUsed = false;
				equips[re.product.eId] = false;
				st.put(re.product.pId, 3);
			}

			for (int i = 0; i < L; i++) {
				Line line = lines[i];
				if (!line.isUsed && !line.products.isEmpty()) {
					Product product = line.products.get(0);

					if (!equips[product.eId]) {
						line.isUsed = true;
						line.currProductId = product.pId;

						equips[product.eId] = true;
						st.put(product.pId, 2);

						requests.add(new Request(currTime + product.mTime, product));
						line.products.remove(0);
					}
				}
			}
		}
	}

	int request(int tStamp, int pId, int mLine, int eId, int mTime) {
		timeFlow(tStamp - 1);

		lines[mLine].products.add(new Product(pId, mLine, eId, mTime));
		requests.add(new Request(tStamp, new Product(-1)));
		st.put(pId, 1);

		currTime = tStamp;
		timeFlow(tStamp);

		return lines[mLine].isUsed ? lines[mLine].currProductId : -1;
	}

	int status(int tStamp, int pId) {
		timeFlow(tStamp);
		if (!st.containsKey(pId)) return 0;
		return st.get(pId);
	}
}

class Solution_d13 {
	private final static int CMD_INIT = 1;
	private final static int CMD_REQUEST = 2;
	private final static int CMD_STATUS = 3;

	private final static UserSolution_d13 usersolution = new UserSolution_d13();

	private static boolean run(BufferedReader br) throws Exception {
		int q = Integer.parseInt(br.readLine());

		int l, m, timestamp, pId, mline, eId, mtime;
		int cmd, ans, ret = 0;
		boolean okay = false;

		for (int i = 0; i < q; ++i) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			cmd = Integer.parseInt(st.nextToken());
			switch (cmd) {
				case CMD_INIT:
					l = Integer.parseInt(st.nextToken());
					m = Integer.parseInt(st.nextToken());
					usersolution.init(l, m);
					okay = true;
					break;
				case CMD_REQUEST:
					timestamp = Integer.parseInt(st.nextToken());
					pId = Integer.parseInt(st.nextToken());
					mline = Integer.parseInt(st.nextToken());
					eId = Integer.parseInt(st.nextToken());
					mtime = Integer.parseInt(st.nextToken());
					ans = Integer.parseInt(st.nextToken());
					ret = usersolution.request(timestamp, pId, mline, eId, mtime);
					if (ret != ans)
						okay = false;
					break;
				case CMD_STATUS:
					timestamp = Integer.parseInt(st.nextToken());
					pId = Integer.parseInt(st.nextToken());
					ans = Integer.parseInt(st.nextToken());
					ret = usersolution.status(timestamp, pId);
					if (ret != ans)
						okay = false;
					break;
				default:
					okay = false;
					break;
			}
		}
		return okay;
	}

	public static void main(String[] args) throws Exception {
		int TC, MARK;

		System.setIn(new java.io.FileInputStream("swea2022/sample_input.txt"));

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		TC = Integer.parseInt(st.nextToken());
		MARK = Integer.parseInt(st.nextToken());

		for (int testcase = 1; testcase <= TC; ++testcase) {
			int score = run(br) ? MARK : 0;
			System.out.println("#" + testcase + " " + score);
		}

		br.close();
	}
}


