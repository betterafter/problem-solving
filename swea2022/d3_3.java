package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class UserSolution_d3_3 {
    char[] nums;
    int maxNum = 0;

    void init() {
        maxNum = 0;
    }

    String charToString(char[] arr) {
        String res = "";
        for (int i = 0; i < arr.length; i++) {
            res += arr[i];
        }
        return res;
    }

    void changer(int idx, int currCnt, int targetCnt) {
        if (currCnt == targetCnt) {
            maxNum = Math.max(Integer.parseInt(charToString(nums)), maxNum); 
            return;
        }
        for (int i = idx; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                char temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;

                changer(i, currCnt + 1, targetCnt);

                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

class Solution_d3_3
{
	public static void main(String args[]) throws Exception
	{
        UserSolution_d3_3 userSolution = new UserSolution_d3_3();
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            String[] input = br.readLine().split(" ");

            userSolution.init();
            userSolution.nums = input[0].toCharArray();
            int C = Integer.parseInt(input[1]);
            
            if (userSolution.nums.length < C) { 
                C = userSolution.nums.length;
            }

            userSolution.changer(0, 0, C);
            bw.write("#" + test_case + " " + userSolution.maxNum + '\n');
 		}
        bw.flush();
	}
}