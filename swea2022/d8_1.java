package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class User_d8_1 {
    int uID, income;
    public User_d8_1(int uID, int income) {
        this.uID = uID;
        this.income = income;
    }
}

class UserSolution_d8_1 {

    private static int MAX = 100001;
    static User_d8_1[] users = new User_d8_1[MAX];
    int size = 0;

	public void init() {
		users = new User_d8_1[MAX];
        size = 0;
	}
	
	public void addUser(int uID, int income) {

        users[size] = new User_d8_1(uID, income);

        int curr = size;
        while (curr > 0) {
            if (check(curr)) {
                User_d8_1 temp = users[curr];
                users[curr] = users[(curr - 1) / 2];
                users[(curr - 1) / 2] = temp;
                curr = (curr - 1) / 2;
            } else break;
        }

        size = size + 1;
	}

    User_d8_1 popUser() {
        User_d8_1 val = users[0];
        size--;
        users[0] = users[size];
        users[size] = null;

        int curr = 0;
        while (curr * 2 + 1 < size) {
            int child;
            if (curr * 2 + 2 == size) child = curr * 2 + 1;
            else {
                if (users[curr * 2 + 1].income > users[curr * 2 + 2].income) child = curr * 2 + 1;
                else if (users[curr * 2 + 1].income == users[curr * 2 + 2].income) {
                    if (users[curr * 2 + 1].uID < users[curr * 2 + 2].uID) {
                        child = curr * 2 + 1;
                    } else child = curr * 2 + 2;
                } else child = curr * 2 + 2;
            }

            if (users[curr].income > users[child].income 
            || (users[curr].income == users[child].income && users[curr].uID < users[child].uID)) break;

            User_d8_1 temp = users[curr];
            users[curr] = users[child];
            users[child] = temp;
            curr = child;
        }

        return val;
    }
	
	int getTop10(int[] result) {
        int length;
        if (10 < size) length = 10;
        else length = size;

        User_d8_1[] temp = new User_d8_1[length];
        for (int i = 0; i < length; i++) {
            User_d8_1 user = popUser();
            temp[i] = user;
            result[i] = user.uID;
        }

        for (int i = 0; i < length; i++) {
            addUser(temp[i].uID, temp[i].income);
        }

        return length;
	}

    boolean check(int curr) {
        if (users[curr].income > users[(curr - 1) /  2].income) return true;
        if (users[curr].income == users[(curr - 1) / 2].income) {
            if (users[curr].uID < users[(curr - 1) / 2].uID) return true;
            else return false;
        }
        return false;
    }
}

class Solution_d8_1 {
	
	private final static int MAX_INPUT = 100000;
	private final static int MAX_NUM = 30000;
	
	private final static UserSolution_d8_1 usersolution = new UserSolution_d8_1();
	
	private static BufferedReader br;
	
	private static int[] input = new int[MAX_INPUT];
	private static long seed = 13410;
	
	private static long pseudoRand() {
		seed = (seed * 214013 + 2531011) & 0xffffffffL;
		return (seed>>11) % MAX_NUM;
	}
	
	private static void makeInput(int inputLen) {
		for(int i = 0; i < inputLen; i++) {
			input[i] = (int)(pseudoRand());
		}
	}
	
	private static int run() throws Exception {
		int score = 100;
		int N, userNum, uID = 0, ret, sum, ans;
		int[] result = new int[10];
		String str;
		
		str = br.readLine();
		N = Integer.parseInt(str);
		
		for(int i = 0; i < N; i++) {
			str = br.readLine();
			userNum = Integer.parseInt(str);
			makeInput(userNum);
			
			for(int j = 0; j < userNum; j++) {
				usersolution.addUser(uID++, input[j]);
			}
			ret = usersolution.getTop10(result);
			
			sum = 0;
			for(int j = 0; j < ret; j++) {
				sum += result[j];
			}
			
			str = br.readLine();
			ans = Integer.parseInt(str);	
            System.out.println("result  : " + sum + " , " + ans);
			if(sum != ans) {
				score = 0;
			}
		}
		return score;
	}
	public static void main(String[] args) throws Exception {
		int TC;
		System.setIn(new java.io.FileInputStream("swea2022/partial_sort_input.txt"));
		
		br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		TC = Integer.parseInt(str);
		
		for (int tc = 1; tc <= TC; tc++) {
			usersolution.init();
			System.out.println("#" + tc + " " + run());
		}
	}
}