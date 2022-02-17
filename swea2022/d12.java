// package swea2022;

// import java.io.BufferedReader;
// import java.io.InputStreamReader;
// import java.util.StringTokenizer;

// class UserSolution
// {
// 	class Point {
// 		int r;
// 		int c;
// 	}

// 	void init(int N, int K, int mHeight[][])
// 	{
        
// 	}

// 	void destroy() {

// 	}

// 	void query(Point mA, Point mB, int mCount, Point mTop[])
// 	{

// 	}

// 	int getHeight(Point mP)
// 	{
// 		return 0;
// 	}

// 	void work(Point mA, Point mB, int mH)
// 	{

// 	}
// }


// class Solution
// {
// 	private static BufferedReader br;
// 	private static UserSolution usersolution = new UserSolution();
// 	private static StringTokenizer st;

// 	private static int mSeed;
// 	private static int pseudo_rand()
// 	{
// 		mSeed = mSeed * 214013 + 2531011;
// 		return (mSeed >> 16) & 0x7FFF;
// 	}

// 	private final static int MAX_MAP_SIZE = 2000;
// 	private final static int MAX_K = 5;

// 	private final static int CMD_INIT = 100;
// 	private final static int CMD_QUERY = 200;
// 	private final static int CMD_HEIGHT = 300;
// 	private final static int CMD_WORK = 400;

// 	private static int[][] map = new int[MAX_MAP_SIZE][MAX_MAP_SIZE];
// 	private static UserSolution.Point[] result = new UserSolution.Point[MAX_K];

// 	private static void make_map(int n, int max_height, int seed)
// 	{
// 		mSeed = seed;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			for (int j = 0; j < n; ++j)
// 			{
// 				map[i][j] = 1 + ((pseudo_rand() << 15) + pseudo_rand()) % max_height;
// 			}
// 		}
// 	}

// 	private static UserSolution.Point coordinates(int seed)
// 	{
// 		UserSolution.Point p = usersolution.new Point();
// 		p.r = seed / MAX_MAP_SIZE + 1;
// 		p.c = seed % MAX_MAP_SIZE + 1;
// 		return p;
// 	}

// 	private static int run() throws Exception
// 	{
// 		for (int i = 0; i < MAX_K; ++i)
// 		{
// 			result[i] = usersolution.new Point();
// 		}

// 		int n;
// 		st = new StringTokenizer(br.readLine(), " ");
// 		n = Integer.parseInt(st.nextToken());

// 		int seed, size, K, max_height;
// 		UserSolution.Point a, b, c;
// 		int seed_a, seed_b, seed_c, d, k;
// 		int ans = 0, ret = 0;
// 		int okay = 0;

// 		for (int i = 0; i < n; ++i)
// 		{
// 			int cmd;
// 			st = new StringTokenizer(br.readLine(), " ");
// 			cmd = Integer.parseInt(st.nextToken());

// 			switch (cmd)
// 			{
// 			case CMD_INIT:
// 				size = Integer.parseInt(st.nextToken());
// 				K = Integer.parseInt(st.nextToken());
// 				max_height = Integer.parseInt(st.nextToken());
// 				seed = Integer.parseInt(st.nextToken());

// 				make_map(size, max_height, seed);

// 				usersolution.init(size, K, map);
// 				okay = 1;
// 				break;
// 			case CMD_QUERY:
// 				seed_a = Integer.parseInt(st.nextToken());
// 				seed_b = Integer.parseInt(st.nextToken());
// 				k = Integer.parseInt(st.nextToken());

// 				a = coordinates(seed_a);
// 				b = coordinates(seed_b);

// 				if (okay == 1)
// 					usersolution.query(a, b, k, result);

// 				for (int j = 0; j < k; ++j)
// 				{
// 					seed_c = Integer.parseInt(st.nextToken());
// 					c = coordinates(seed_c);
// 					if (c.r != result[j].r || c.c != result[j].c)
// 						okay = 0;
// 				}
// 				break;
// 			case CMD_HEIGHT:
// 				seed_a = Integer.parseInt(st.nextToken());
// 				a = coordinates(seed_a);

// 				if (okay == 1)
// 					ret = usersolution.getHeight(a);

// 				ans = Integer.parseInt(st.nextToken());

// 				if (ans != ret)
// 					okay = 0;
// 				break;
// 			case CMD_WORK:
// 				seed_a = Integer.parseInt(st.nextToken());
// 				seed_b = Integer.parseInt(st.nextToken());
// 				d = Integer.parseInt(st.nextToken());
// 				a = coordinates(seed_a);
// 				b = coordinates(seed_b);

// 				if (okay == 1)
// 					usersolution.work(a, b, d);
// 				break;
// 			default:
// 				okay = 0;
// 				break;
// 			}
// 		}
// 		usersolution.destroy();

// 		return okay;
// 	}

// 	public static void main(String[] args) throws Exception
// 	{	
// 		int T, Mark;
// 		//System.setIn(new java.io.FileInputStream("res/sample_input.txt"));

// 		br = new BufferedReader(new InputStreamReader(System.in));

// 		StringTokenizer stinit = new StringTokenizer(br.readLine(), " ");
// 		T = Integer.parseInt(stinit.nextToken());
// 		Mark = Integer.parseInt(stinit.nextToken());
// 		for (int tc = 1; tc <= T; tc++)
// 		{
// 			if (run() == 1) 
// 				System.out.println("#" + tc + " " + Mark);
// 			else
// 				System.out.println("#" + tc + " 0");
// 		}

// 		br.close();
// 	}
// }