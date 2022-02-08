package swea2022;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

class UserSolution_d9_4 {

    class User {
        String name, number, birthday, email, memo;
        
        public User () { }
        public User (String name, String number, String birthday, String email, String memo) {
            this.name = name;
            this.number = number;
            this.birthday = birthday;
            this.email = email;
            this.memo = memo;
        }

        public String getValue(int field) {
            switch (field) {
                case 0 : return this.name;
                case 1 : return this.number;
                case 2 : return this.birthday;
                case 3 : return this.email;
                case 4 : return this.memo;
                default : return null;
            }
        }

        public void change(int field, String val) {
            switch (field) {
                case 0 : 
                    this.name = val;
                    break;
                case 1 : 
                    this.number = val;
                    break;
                case 2 : 
                    this.birthday = val;
                    break;
                case 3 : 
                    this.email = val;
                    break;
                case 4 : 
                    this.memo = val;
                    break;
                default : 
                    break;
            }
        }
    }

    static int cnt = 0;
    HashMap<Integer, User> map = new HashMap<>();
    HashMap<String, ArrayList<Integer>>[] fieldMap;
    User[] users = new User[50010];

    User getUser(String name, String number, String birthday, String email, String memo) {
        if (users[cnt] == null) {
            users[cnt] = new User(name, number, birthday, email, memo);
        } else {
            users[cnt].name = name;
            users[cnt].number = number;
            users[cnt].birthday = birthday;
            users[cnt].email = email;
            users[cnt].memo = memo;
        }
        return users[cnt];
    }

	void InitDB()
	{
        map.clear();
        fieldMap = new HashMap[] {
            new HashMap<>(), new HashMap<>(), new HashMap<>(),
            new HashMap<>(), new HashMap<>()
        };
        cnt = 0;
	}

	void Add(String name, String number, String birthday, String email, String memo)
	{
        map.put(cnt, getUser(name, number, birthday, email, memo));
        List<String> list = Arrays.asList(name, number, birthday, email, memo);
        for (int i = 0; i < 5; i++) {
            if (!fieldMap[i].containsKey(list.get(i))) {
                ArrayList<Integer> l = new ArrayList<>();
                l.add(cnt);
                fieldMap[i].put(list.get(i), l);

            } else fieldMap[i].get(list.get(i)).add(cnt);
        }
        cnt++;
	}

	int Delete(int field, String str)
	{
        int ans = 0;
        if (!fieldMap[field].containsKey(str)) return ans;
        ArrayList<Integer> list = fieldMap[field].get(str);

        for (int i = 0; i < list.size(); i++) {
            if (map.containsKey(list.get(i))) {
                map.remove(list.get(i));
                ans++;
            }
        }
        
        fieldMap[field].remove(str);
		return ans;
	}

	int Change(int field, String str, int changefield, String changestr)
	{
        int ans = 0;
        if (!fieldMap[field].containsKey(str)) return ans;
        if (!fieldMap[changefield].containsKey(changestr)) {
            fieldMap[changefield].put(changestr, new ArrayList<>());
        }

        ArrayList<Integer> list = fieldMap[field].get(str);
        Iterator<Integer> iter = list.iterator();
        while (iter.hasNext()) {
            int key = iter.next();
            if (map.containsKey(key)) {
                User user = map.get(key);
                String prev = user.getValue(changefield);
                user.change(changefield, changestr);

                if (field != changefield) {
                    ArrayList<Integer> plist = fieldMap[changefield].get(prev);
                    for (int i = 0; i < plist.size(); i++) {
                        if (plist.get(i) == key) {
                            plist.remove(i);
                            break;
                        }
                    }
                }

                fieldMap[changefield].get(changestr).add(key);
                ans++;
            }
        }

        if (field == changefield) fieldMap[field].remove(str);
		return ans;
	}

	Solution_d9_4.Result Search(int field, String str, int returnfield)
	{
		Solution_d9_4.Result result = new Solution_d9_4.Result();
		result.count = 0;

        if (!fieldMap[field].containsKey(str)) return result;
        ArrayList<Integer> list = fieldMap[field].get(str);

        for (int i = 0; i < list.size(); i++) {
            if (map.containsKey(list.get(i))) {
                result.str = map.get(list.get(i)).getValue(returnfield);
                result.count++;
            }
        }
		return result;
	}
}


interface Field 
{
	public final static int NAME     = 0;
	public final static int NUMBER   = 1;
	public final static int BIRTHDAY = 2;
	public final static int EMAIL    = 3;
	public final static int MEMO     = 4;
}

class Solution_d9_4 
{
	private final static int CMD_INIT   = 0;
	private final static int CMD_ADD    = 1;
	private final static int CMD_DELETE = 2;
	private final static int CMD_CHANGE = 3;
	private final static int CMD_SEARCH = 4;
	
	static class Result
	{
        public int count;                                
        public String str;
	}
	
	private static Scanner sc;
	private static UserSolution_d9_4 userSolution = new UserSolution_d9_4();

	private static int Score;
	private static int ScoreIdx;
	private static String name, number, birthday, email, memo;

	private static String lastname[] = { "kim", "lee", "park", "choi", "jung", "kang", "cho", "oh", "jang", "lim" };
	private static int lastname_length[] = { 3, 3, 4, 4, 4, 4, 3, 2, 4, 3 };

	private static int mSeed;
	private static int mrand(int num)
	{
		mSeed = mSeed * 1103515245 + 37209;
		if (mSeed < 0) mSeed *= -1;
		return ((mSeed >> 8) % num);
	}

	private static void make_field(int seed)
	{
		StringBuilder sbname = new StringBuilder();
		StringBuilder sbnumber = new StringBuilder();
		StringBuilder sbbirthday = new StringBuilder();
		StringBuilder sbemail = new StringBuilder();
		StringBuilder sbmemo = new StringBuilder();

		int name_length, email_length, memo_length;
		int num;

		mSeed = seed;

		name_length = 6 + mrand(10);
		email_length = 10 + mrand(10);
		memo_length = 5 + mrand(10);		

		num = mrand(10);
		sbname.append(lastname[num]);
		for (int i = 0; i < name_length - lastname_length[num]; i++) sbname.append((char)('a' + mrand(26)));

		for (int i = 0; i < memo_length; i++) sbmemo.append((char)('a' + mrand(26)));

		for (int i = 0; i < email_length - 6; i++) sbemail.append((char)('a' + mrand(26)));
		sbemail.append("@");
		sbemail.append((char)('a' + mrand(26)));
		sbemail.append(".com");

		sbnumber.append("010");
		for (int i = 0; i < 8; i++) sbnumber.append((char)('0' + mrand(10)));

		sbbirthday.append("19");
		num = mrand(100);
		sbbirthday.append((char)('0' + num / 10));
		sbbirthday.append((char)('0' + num % 10));
		num = 1 + mrand(12);
		sbbirthday.append((char)('0' + num / 10));
		sbbirthday.append((char)('0' + num % 10));
		num = 1 + mrand(30);
		sbbirthday.append((char)('0' + num / 10));
		sbbirthday.append((char)('0' + num % 10));
		
		name = sbname.toString();
		number = sbnumber.toString();
		birthday = sbbirthday.toString();
		email = sbemail.toString();
		memo = sbmemo.toString();
	}

	private static void cmd_init()
	{
		ScoreIdx = Integer.parseInt(sc.next());

		userSolution.InitDB();
	}

	private static void cmd_add()
	{
		int seed = Integer.parseInt(sc.next());

		make_field(seed);

		userSolution.Add(name, number, birthday, email, memo);
	}

	private static void cmd_delete()
	{
		int field = Integer.parseInt(sc.next());
		String str = sc.next();
		int check = Integer.parseInt(sc.next());
		
		int result = userSolution.Delete(field, str);
        //System.out.println("delete : " + result + " " + check + " " + (result == check));
		if (result != check)
			Score -= ScoreIdx;
	}

	private static void cmd_change()
	{
		int field = Integer.parseInt(sc.next());
		String str = sc.next();
		int changefield = Integer.parseInt(sc.next());
		String changestr = sc.next();
		int check = Integer.parseInt(sc.next());

        int result = userSolution.Change(field, str, changefield, changestr);
        //System.out.println("change : " + result + " " + check + " " + (result == check));
		if (result != check)
			Score -= ScoreIdx;
	}

	private static void cmd_search()
	{
		int field = Integer.parseInt(sc.next());
		String str = sc.next();
		int returnfield = Integer.parseInt(sc.next());
		String checkstr = sc.next();
		int check = Integer.parseInt(sc.next());
		
		Result result = userSolution.Search(field, str, returnfield);
		if (result.count != check || (result.count == 1 && !checkstr.equals(result.str)))
			Score -= ScoreIdx;
	}

	private static void run()
	{
		int N = Integer.parseInt(sc.next());
        System.out.println(N);
		for (int i = 0; i < N; i++)
		{
			int cmd = Integer.parseInt(sc.next());
			switch (cmd)
			{
			case CMD_INIT:   cmd_init(); break;
			case CMD_ADD:    cmd_add(); break;
			case CMD_DELETE: cmd_delete(); break;
			case CMD_CHANGE: cmd_change(); break;
			case CMD_SEARCH: cmd_search(); break;
			default: break;
			}
		}
	}
	
	private static void init()
	{
		Score = 1000;
		ScoreIdx = 1;
	}	
	
	public static void main(String[] args) throws Exception
	{
		System.setIn(new java.io.FileInputStream("swea2022/eval_input.txt"));
		
		sc = new Scanner(System.in);

		int T = sc.nextInt();
		int TotalScore = 0;	
		for (int tc = 1; tc <= T; tc++)
		{
			init();
			
			run();
			
			if (Score < 0)
				Score = 0;

			TotalScore += Score;

			System.out.println("#" + tc + " " + Score);
		}
		System.out.println("TotalScore = " + TotalScore);
		sc.close();
	}
}