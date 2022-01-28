package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution_d6_4
{
    static int MAX = 10000000, EMPTY = -1, BOMB = -2;
    static int N, res = 0;
    static int[][] map = new int[301][301];
    static boolean[][] visit = new boolean[301][301];
    static int[][] dir = new int[][] { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

    static int check(int x, int y, int[][] map) {
        int res = 0;
        for (int i = 0; i < 8; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (map[ny][nx] == BOMB) res++;
            }
        }
        return res;
    }

    static void dfs(int x, int y) {
        map[y][x] = 0;
        visit[y][x] = true;
        for (int i = 0; i < 8; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[ny][nx] != BOMB) {
                int cnt = check(nx, ny, map);
                if (cnt == 0 && !visit[ny][nx]) {
                    dfs(nx, ny);
                } else map[ny][nx] = cnt;
            }
        }
    }

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            res = 0;
            N = Integer.parseInt(br.readLine());
            map = new int[301][301];
            visit = new boolean[301][301];

            for (int i = 0; i < N; i++) {
                String input = br.readLine();
                for (int j = 0; j < N; j++) {
                    if (input.charAt(j) == '*') map[i][j] = BOMB;
                    else map[i][j] = EMPTY;
                }
            }

            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (map[y][x] != BOMB && check(x, y, map) == 0 && !visit[y][x]) {
                        dfs(x, y);
                        res++;
                    }
                }
            }

            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (map[y][x] == -1) res++;
                }
            }

            System.out.println("#" + test_case + " " + res);
 		}
	}
}