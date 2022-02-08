package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution_d9_3
{
    static int DIV = 1 << 18;
    static int WIDTH_HASH = 5381;
    static int HEIGHT_HASH = 10007;
    static int H = 0, W = 0, N = 0, M = 0;
    static int ans = 0;

    static int[][] teacher = new int[2001][2001];
    static int[][] child = new int[2001][2001];

    // 가로줄만 해싱하기 (child, parent 둘 다 모든 가로줄에 대하여. parent는 child의 가로줄의 길이 만큼만)
    static void hashing(String[] str1, String[] str2) {
        for (int idx = 0; idx < N; idx++) {
            int phash = 0, chash = 0, power = 1;
            for (int i = 0; i <= M - W; i++) {
                // 처음에는 가로줄 초기화
                if (i == 0) {
                    for (int j = 0; j < W; j++) {
                        phash += str1[idx].charAt(W - 1 - j) * power;
                        if (idx < H) chash += str2[idx].charAt(W - 1 - j) * power;
                        if (j != W - 1) power *= WIDTH_HASH;
                    }
                    teacher[idx][0] = phash;
                    if (idx < H) child[idx][0] = chash;
                    // 그 이후엔 옆으로 이동하면서 해시 갱신
                } else {
                    phash = WIDTH_HASH * (phash - str1[idx].charAt(i - 1) * power) + str1[idx].charAt(W - 1 + i);
                    teacher[idx][i] = phash;
                }
            }
        }
    }

    static void chashing() {
        for (int w = 0; w <= M - W; w++) {
            int phash = 0, chash = 0, power = 1;
            for (int h = 0; h <= N - H; h++) {
                if (h == 0) {
                    for (int i = 0; i < H; i++) {
                        phash += teacher[H - 1 - i][w] * power;
                        chash += child[H - 1 - i][0] * power;
                        if (i != H - 1) power *= HEIGHT_HASH;
                    }
                } else {
                    phash = HEIGHT_HASH * (phash - teacher[h - 1][w] * power) + teacher[H - 1 + h][w];
                }
                if (phash == chash) ans++;
            }
        }      
    }

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            ans = 0;

            String[] input = br.readLine().split(" ");
            H = Integer.parseInt(input[0]);
            W = Integer.parseInt(input[1]);
            N = Integer.parseInt(input[2]);
            M = Integer.parseInt(input[3]);
            
            String[] str1 = new String[H];
            String[] str2 = new String[N];
            for (int i = 0; i < H; i++) {
                str1[i] = br.readLine();
            }
            for (int i = 0; i < N; i++) {
                str2[i] = br.readLine();
            }

            hashing(str2, str1);
            chashing();

            System.out.println("#" + test_case + " " + ans);
 		}
        bw.flush();
	}
}