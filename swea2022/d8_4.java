package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution
{
    static int MAX = 400010;
    static int[] mxh = new int[MAX];
    static int[] mnh = new int[MAX];
    static int mxsize = 1;
    static int mnsize = 1;

    static void mxpush(int val) {
        mxh[mxsize] = val;

        int curr = mxsize;
        while (curr > 1) {
            int parent = curr / 2;
            if (mxh[parent] > mxh[curr]) break;

            int temp = mxh[parent];
            mxh[parent] = mxh[curr];
            mxh[curr] = temp;

            curr = parent;
        }

        mxsize++;
    }

    static int mxpop() {
        int val = mxh[1];
        mxsize--;
        mxh[1] = mxh[mxsize];

        int curr = 1;
        while (curr * 2 < mxsize) {
            int child;
            if (curr * 2 + 1 == mxsize) child = curr * 2;
            else child = mxh[curr * 2] > mxh[curr * 2 + 1] ? curr * 2 : curr * 2 + 1;
            if (mxh[curr] > mxh[child]) break;

            int temp = mxh[child];
            mxh[child] = mxh[curr];
            mxh[curr] = temp;

            curr = child;
        }

        return val;
    }

    static void mnpush(int val) {
        mnh[mnsize] = val;

        int curr = mnsize;
        while (curr > 1) {
            int parent = curr / 2;
            if (mnh[parent] < mnh[curr]) break;

            int temp = mnh[parent];
            mnh[parent] = mnh[curr];
            mnh[curr] = temp;

            curr = parent;
        }

        mnsize++;
    }

    static int mnpop() {
        int val = mnh[1];
        mnsize--;
        mnh[1] = mnh[mnsize];

        int curr = 1;
        while (curr * 2 < mnsize) {
            int child;

            if (curr * 2 + 1 == mnsize) child = curr * 2;
            else child = mnh[curr * 2] < mnh[curr * 2 + 1] ? curr * 2 : curr * 2 + 1;
            if (mnh[curr] < mnh[child]) break;

            int temp = mnh[child];
            mnh[child] = mnh[curr];
            mnh[curr] = temp;

            curr = child;
        }

        return val;
    }
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            long result = 0;
            mxsize = 1;
            mnsize = 1;

            String[] input = br.readLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int A = Integer.parseInt(input[1]);
            mxpush(A);

            for (int i = 0; i < N; i++) {
                String[] input2 = br.readLine().split(" ");
                int X = Integer.parseInt(input2[0]);
                int Y = Integer.parseInt(input2[1]);

                if (X <= mxh[1]) mxpush(X);
                else mnpush(X);

                if (Y <= mxh[1]) mxpush(Y);
                else mnpush(Y);

                if (mxsize == mnsize + 3) {
                    int val = mxpop();
                    mnpush(val);
                } else if (mxsize + 1 == mnsize) {
                    int val = mnpop();
                    mxpush(val);
                }

                result = (result + mxh[1]) % 20171109;
            }

            bw.write("#" + test_case + " " + result % 20171109 + '\n');
        }
        bw.flush();
	}
}