package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

class UserSolution
{	
	class Particle {
		int px, py, pz, vx, vy, vz;
		public Particle(int mPx, int mPy, int mPz, int mVx, int mVy, int mVz) {
			this.px = mPx;
			this.py = mPy;
			this.pz = mPz;
			this.vx = mVx;
			this.vy = mVy;
			this.vz = mVz;
		}
	}

	HashMap<Integer, Particle> particles = new HashMap<>();

	int L, R;
	int[][][][] XYZ = new int[10][10][10][100];
	int[][][] sz = new int[10][10][10];
	int BOUND = L;
	int currId = 1;

	public void init(int L, int R)
	{
		for (int x = 0; x < 10; ++x) 
			for (int y = 0; y < 10; ++y) 
				for (int z = 0; z < 10; z++)
					sz[x][y][z] = 0;

		this.L = L;
		this.R = R;

		BOUND = L;
		currId = 1;
		particles.clear();
	}

	public void insertParticle(int mID, int mPx, int mPy, int mPz, int mVx, int mVy, int mVz)
	{
		particles.put(mID, new Particle(mPx, mPy, mPz, mVx, mVy, mVz));
		
		int xn = Math.min(9, (particles.get(mID).px + L) / (L / 5));
		int yn = Math.min(9, (particles.get(mID).py + L) / (L / 5));
		int zn = Math.min(9, (particles.get(mID).pz + L) / (L / 5));
		XYZ[xn][yn][zn][sz[xn][yn][zn]++] = mID;
		currId = mID;
	}

	public void removeParticle(int mID)
	{
		particles.remove(mID);
	}

	public int findNearParticle(int mID)
	{
		Particle p = particles.get(mID);
		int ret = 0;

		int xn = Math.min(9, (p.px + L) / (L / 5));
		int yn = Math.min(9, (p.py + L) / (L / 5));
		int zn = Math.min(9, (p.pz + L) / (L / 5));

		for (int x = Math.max(0, xn - 1); x <= Math.min(9, xn + 1); ++x) {
			for (int y = Math.max(0, yn - 1); y <= Math.min(9, yn + 1); ++y) {
				for (int z = Math.max(0, zn - 1); z <= Math.min(9, zn + 1); ++z) {
					for (int i = 0; i < sz[x][y][z]; ++i) {
						int n = XYZ[x][y][z][i];
						if (!particles.containsKey(n)) continue;
						Particle op = particles.get(n);
						int xd = Math.abs(p.px - op.px);
						int yd = Math.abs(p.py - op.py);
						int zd = Math.abs(p.pz - op.pz);
						if (xd * xd + yd * yd + zd * zd <= R * R) ret += n;
					}
				}
			}
		}
		return ret - mID;
	}

	public void go(int mTick)
	{
		for (int x = 0; x < 10; ++x) for (int y = 0; y < 10; ++y) for (int z = 0; z < 10; ++z) sz[x][y][z] = 0;
		int[] col = new int[3];

		for (int i = 0; i < mTick; i++) {
			Iterator<Integer> iter = particles.keySet().iterator();
			while (iter.hasNext()) {
				int id = iter.next();
				Particle p = particles.get(id);

				while (true) {
					int x = p.px, y = p.py, z = p.pz;
					int vx = p.vx, vy = p.vy, vz = p.vz;
					int nx = x + vx, ny = y + vy, nz = z + vz;
	
					if (nx > L) col[0] = 1;
					else if (nx < -L) col[0] = -1;
					else col[0] = 0;
	
					if (ny > L) col[1] = 1;
					else if (ny < -L) col[1] = -1;
					else col[1] = 0;
	
					if (nz > L) col[2] = 1;
					else if (nz < -L) col[2] = -1;
					else col[2] = 0;

					// X = L or X = -L
					if (col[0] == 1) { nx = 2 * L - nx; vx = -vx; }
					else if (col[0] == -1) { nx = -2 * L - nx; vx = -vx; }

					// Y = L or Y = -L
					if (col[1] == 1) { ny = 2 * L - ny; vy = -vy; }
					else if (col[1] == -1) { ny = -2 * L - ny; vy = -vy; }

					// Z = L or Z = -L
					if (col[2] == 1) { nz = 2 * L - nz; vz = -vz; }
					else if (col[2] == -1) { nz = -2 * L - nz; vz = -vz; }

					p.px = nx; p.py = ny; p.pz = nz;
					p.vx = vx; p.vy = vy; p.vz = vz;

					if (nx >= -L && nx <= L && ny >= -L && ny <= L && nz >= -L && nz <= L) break;
				}
			}
		}

		Iterator<Integer> iter = particles.keySet().iterator();
		while (iter.hasNext()) {
			int id = iter.next();
			Particle p = particles.get(id);

			int xn = Math.min(9, (p.px + L) / (L / 5));
			int yn = Math.min(9, (p.py + L) / (L / 5));
			int zn = Math.min(9, (p.pz + L) / (L / 5));
			XYZ[xn][yn][zn][sz[xn][yn][zn]++] = id;
		}
	}
}

class Solution
{	
	private final static int INIT				= 100;
	private final static int INSERT_PARTICLE	= 200;
	private final static int REMOVE_PARTICLE	= 300;
	private final static int FIND_NEAR_PARTICLE	= 400;
	private final static int GO					= 500;
	
	private static int mSeed;
	private static int pseudo_rand()
	{
		mSeed = mSeed * 214013 + 2531011;
		return (int)((mSeed >> 16) & 0x7FFF);
	}
	
	private final static UserSolution usersolution = new UserSolution();
	
	static boolean run(BufferedReader br) throws Exception
	{
		int Q;
		int L = 0, R;

		int mID;
		int mPx, mPy, mPz, mVx, mVy, mVz;
		int mTick;
		
		int ret = -1, ans;
		int mSeq = 1;
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		Q     = Integer.parseInt(st.nextToken());
		mSeed = Integer.parseInt(st.nextToken());
		
	    boolean okay = false;
		for (int q = 0; q < Q; ++q)
		{
			st = new StringTokenizer(br.readLine(), " ");

			int cmd = Integer.parseInt(st.nextToken());
			switch(cmd)
			{
			case INIT:
				L = Integer.parseInt(st.nextToken());
				R = Integer.parseInt(st.nextToken());
				usersolution.init(L, R);
				okay = true;
				break;
			case INSERT_PARTICLE:
				mPx = pseudo_rand() % (L + L - 1) - L + 1;
				mPy = pseudo_rand() % (L + L - 1) - L + 1;
				mPz = pseudo_rand() % (L + L - 1) - L + 1;
				mVx = pseudo_rand() % (L + L + 1) - L;
				mVy = pseudo_rand() % (L + L + 1) - L;
				mVz = pseudo_rand() % (L + L + 1) - L;
				if (okay)
					usersolution.insertParticle(mSeq, mPx, mPy, mPz, mVx, mVy, mVz);
				++mSeq;
				break;
			case REMOVE_PARTICLE:
				mID = Integer.parseInt(st.nextToken()) ;
				if (okay)
					usersolution.removeParticle(mID);
				break;
			case FIND_NEAR_PARTICLE:
				mID = Integer.parseInt(st.nextToken()) ;
				if (okay)
					ret = usersolution.findNearParticle(mID);
				ans = Integer.parseInt(st.nextToken()) ;;
				//System.out.println(ans + " , " + ret);
				if (ans != ret)
					okay = false;
				break;
			case GO:
				mTick = Integer.parseInt(st.nextToken()) ;;
				if (okay)
					usersolution.go(mTick);
				break;
			default:
				okay = false;
				break;
			}
		}

	    return okay;
	}


	public static void main(String[] args) throws Exception
	{
		int TC, MARK;

		System.setIn(new java.io.FileInputStream("swea2022/sample_input.txt"));
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		TC = Integer.parseInt(st.nextToken());
		MARK = Integer.parseInt(st.nextToken());

		for (int testcase = 1; testcase <= TC; ++testcase)
		{
            int score = run(br) ? MARK : 0;
            System.out.println("#" + testcase + " " + score);
		}

		br.close();
	}
}