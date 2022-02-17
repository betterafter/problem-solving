package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class UserSolution
{	
	public void init(int L, int R)
	{

	}

	public void insertParticle(int mID, int mPx, int mPy, int mPz, int mVx, int mVy, int mVz)
	{
		
	}

	public void removeParticle(int mID)
	{
		
	}

	public int findNearParticle(int mID)
	{
		return -1;
	}

	public void go(int mTick)
	{
		
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

		//System.setIn(new java.io.FileInputStream("res/sample_input.txt"));
		
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