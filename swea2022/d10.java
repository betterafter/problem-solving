package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class UserSolution
{
    ArrayList<Character>[] memo = new ArrayList[301];
    int[][] count = new int[301][27];
    int H, W, MH;
    int row, col;

	void init(int H, int W, char mStr[])
	{
        this.H = H; this.W = W; this.MH = 1;
        this.row = 0; this.col = 0;
        
        for (int i = 0; i < 300; i++) {
            for (int j = 0; j < 27; j++) {
                count[i][j] = 0;
            }
        }
        for (int i = 0; i < 300; i++) {
            if (memo[i] == null) memo[i] = new ArrayList<>(301);
            else memo[i].clear();
            memo[i].add('\0');
        }

        for (int i = 0; mStr[i] != '\0'; i++) {
            insert(mStr[i]);
        }

        this.row = 0; this.col = 0;
	}
	
	void insert(char mChar)
	{
        if (col >= W) {
            row = row + 1; col = 0; MH = row + 1;
        }
    
        memo[row].add(col, mChar);
        count[row][mChar - 'a']++;

        for (int i = row; i < H; i++) {
            if (memo[i].size() > W + 1) {
                char pc = memo[i].remove(memo[i].size() - 2);
                count[i][pc - 'a']--;
                memo[i + 1].add(0, pc);
                count[i + 1][pc - 'a']++;

                MH = i + 2;
            } else break;
        }

        col = col + 1;
	}

	char moveCursor(int mRow, int mCol)
	{   
        mRow--; mCol--;
        if (mRow >= MH) {
            row = MH - 1; col = memo[row].size() - 1;
            return '$';
        } 
        
        if (mCol >= memo[mRow].size()) {
            row = mRow; col = memo[row].size() - 1;
            return '$';
        }

        row = mRow; col = mCol;
        
        return memo[row].get(col);
	}

	int countCharacter(char mChar)
	{
        int curr = count[row][mChar - 'a'];
        for (int i = 0; i < col; i++) {
            if (memo[row].get(i) == mChar) curr--;
        }

        for (int i = row + 1; i < H; i++) {
            curr += count[i][mChar - 'a'];
        }
        if (curr < 0) return 0;
		return curr;
	}
}

class Solution
{
	private final static int CMD_INIT       = 100;
	private final static int CMD_INSERT     = 200;
	private final static int CMD_MOVECURSOR = 300;
	private final static int CMD_COUNT      = 400;
	
	private final static UserSolution usersolution = new UserSolution();
	
	private static void String2Char(char[] buf, String str, int maxLen)
	{
		for (int k = 0; k < str.length(); k++)
			buf[k] = str.charAt(k);
			
		for (int k = str.length(); k <= maxLen; k++)
			buf[k] = '\0';
	}
	
	private static char[] mStr = new char[90001];
	
	private static boolean run(BufferedReader br) throws Exception
	{
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int queryCnt = Integer.parseInt(st.nextToken());
		boolean correct = false;
		
		for (int q = 0; q < queryCnt; q++)
		{
			st = new StringTokenizer(br.readLine(), " ");
			
			int cmd = Integer.parseInt(st.nextToken());
			
			if (cmd == CMD_INIT)
			{
				int H = Integer.parseInt(st.nextToken());
				int W = Integer.parseInt(st.nextToken());
				
				String2Char(mStr, st.nextToken(), 90000);
				
				usersolution.init(H, W, mStr);
				correct = true;
			}
			else if (cmd == CMD_INSERT)
			{
				char mChar = st.nextToken().charAt(0);
				
				usersolution.insert(mChar);
			}
			else if (cmd == CMD_MOVECURSOR)
			{
				int mRow = Integer.parseInt(st.nextToken());
				int mCol = Integer.parseInt(st.nextToken());
				
				char ret = usersolution.moveCursor(mRow, mCol);
				
				char ans = st.nextToken().charAt(0);
				if (ret != ans)
				{
					correct = false;
				}
			}
			else if (cmd == CMD_COUNT)
			{
				char mChar = st.nextToken().charAt(0);
				
				int ret = usersolution.countCharacter(mChar);
				
				int ans = Integer.parseInt(st.nextToken());
				if (ret != ans)
				{
					correct = false;
				}
			}
		}
		return correct;
	}

	public static void main(String[] args) throws Exception
	{
		int TC, MARK;
		
		System.setIn(new java.io.FileInputStream("swea2022/sample_input (2).txt"));
		
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