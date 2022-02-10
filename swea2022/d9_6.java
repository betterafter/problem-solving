package swea2022;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

class Pair_d9_6 {
    String first;
    int second;
    public Pair_d9_6(String first, int second) {
        this.first = first;
        this.second = second;
    }
}

class UserSolution_d9_6 {

    int N = 0;
    HashMap<Integer, String> idxTable = new HashMap<>();
    HashMap<String, ArrayList<Integer>> hashTable = new HashMap<>();
    char[] init_string;

    void init(int N, char[] init_string) {
        this.N = N;
        this.init_string = init_string;
        idxTable.clear();
        hashTable.clear();

        for (int i = 0; i <= this.N - 3; i++) {
            String str = "";
            for (int j = 0; j < 3; j++) {
                str += init_string[i + j];
            }
            idxTable.put(i, str);
            if (hashTable.containsKey(str)) {
                hashTable.get(str).add(i);
            } else {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(i);
                hashTable.put(str, list);
            }
        }
    }

    int change(char[] string_A, char[] string_B) {
        String a = "";
        for (int i = 0; i < 3; i++)  a += string_A[i];
        
        int cnt = 0;
        if (!hashTable.containsKey(a)) return cnt;

        // System.out.println("");
        // System.out.printf(a + " -> ");
        // for (int i = 0; i < 3; i++) {
        //     System.out.print(string_B[i]);
        // }
        // System.out.println("");

        HashMap<Integer, String> tmap = new HashMap<>();

        int curr = -10;
        Collections.sort(hashTable.get(a));
        Iterator<Integer> iter = hashTable.get(a).iterator();
        while (iter.hasNext()) {
            int idx = iter.next();
            // 원래 저장되어 있던 값의 해시가 모종의 이유로 변경되었는지 체크s
            if (idxTable.get(idx).compareTo(a) == 0 && Math.abs(curr - idx) >= 3) {
                //System.out.println(idx + " -> hit");
                curr = idx;
                init_string[idx] = string_B[0];
                init_string[idx + 1] = string_B[1];
                init_string[idx + 2] = string_B[2];

                for (int i = idx - 2; i <= idx + 2; i++) {
                    if (i < 0 || i > N - 3) continue;
                    String val = charToString(init_string[i], init_string[i + 1], init_string[i + 2]);
                    tmap.put(i, val);
                }
                cnt++;
            }
            //else if (idxTable.get(idx).compareTo(a) == 0 && Math.abs(curr - idx) < 3) System.out.println(idx + " -> fail");
            //else System.out.print(idx);
            iter.remove();
        }

        Iterator<Integer> it = tmap.keySet().iterator();
        while (it.hasNext()) {
            int idx = it.next();
            String val = tmap.get(idx);
            idxTable.put(idx, val);
            if (hashTable.containsKey(val)) hashTable.get(val).add(idx);
            else {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(idx);
                hashTable.put(val, list);
            }
        }

        // for (int i = 0; i < temp.size(); i++) {
        //     Pair_d9_6 p = temp.get(i);
        //     String val = p.first; int idx = p.second;
        //     if (hashTable.containsKey(val)) hashTable.get(val).add(idx);
        //     else {
        //         ArrayList<Integer> list = new ArrayList<>();
        //         list.add(idx);
        //         hashTable.put(val, list);
        //     }
        // }

        // for (int i = 0; i < N; i++) {
        //     System.out.print(init_string[i]);
        // }
        // System.out.println("");

        return cnt;
    }

    void result(char[] ret) {
        for (int i = 0; i < N; i++) {
            ret[i] = init_string[i];
        }
    }

    String charToString(char a, char b , char c) {
        String val = "";
        val += a; val += b; val += c;
        return val;
    }
}

class Solution_d9_6 {
	
	private static int mSeed = 5;
	
	private static final int MAXL = 50005;
	private static final int DUMMY_LEN = 5959;
	private static int score = 0;
	private static int total_score = 0;
	
	private static Scanner sc;
	private static UserSolution_d9_6 user = new UserSolution_d9_6();
	
	private static char dummy1[] = new char[DUMMY_LEN];
	private static char init_string[] = new char[MAXL];
	private static char dummy2[] = new char[DUMMY_LEN];
	private static char result_string[] = new char[MAXL];
	private static char dummy3[] = new char[DUMMY_LEN];
	private static char user_ans_string[] = new char[MAXL];
	private static char dummy4[] = new char[DUMMY_LEN];
	private static char string_A[] = new char[4];
	private static char string_B[] = new char[4];
	private static int init_string_len = 0;
	private static int char_type = 0;
	private static int query_cnt = 0;
	
	private static int pseudo_rand()
	{
		mSeed = mSeed * 214013 + 2531011;
		return (mSeed >> 16) & 0x7FFF;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new java.io.FileInputStream("swea2022/sample_input.txt"));
		
		sc = new Scanner(System.in);

		int T = sc.nextInt();
		total_score = 0;
		for (int TC = 1; TC <= T; TC++) {
			score = 100;
			mSeed = sc.nextInt();
			init_string_len = sc.nextInt();
			char_type = sc.nextInt();
			query_cnt = sc.nextInt();
			
			for (int i = 0; i < init_string_len; i++)
			{
				init_string[i] = (char)(pseudo_rand() % char_type + 'a');
			}
			init_string[init_string_len] = '\0';

			user.init(init_string_len, init_string);

			string_A[3] = string_B[3] = '\0';
			for (int i = 0; i < query_cnt; i++)
			{
				for (int k = 0; k < 3; k++)
				{
					string_A[k] = (char) ((pseudo_rand() % char_type) + 'a');
					string_B[k] = (char) ((pseudo_rand() % char_type) + 'a');
				}
				int user_ans = user.change(string_A, string_B);
				int ans = sc.nextInt();

                //System.out.println(ans + " " + user_ans);
				if (ans != user_ans)
				{
					score = 0;
				}
			}

			user.result(user_ans_string);
			
			
			sc.nextLine();
			String result_str_java = sc.nextLine();
			result_string = result_str_java.toString().toCharArray();

			for (int i = 0; i < init_string_len; i++)
			{
				if (result_string[i] != user_ans_string[i])
				{
					score = 0;
					break;
				}
			}

			total_score += score;
			System.out.println("#" + TC +" " + score);
			
		}
		System.out.println("Total score : " + total_score/T);
		sc.close();
	}

	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////

}
