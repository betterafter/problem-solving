package swea2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

class Pair_d8_3<T, E> {
    int first, second;
    public Pair_d8_3(int first, int second) {
        this.first  = first;
        this.second = second;
    }
}

class Solution_d8_3
{
    static int MAX = 1000000;
    static int[][] map = new int[101][101];
    static int[][] val = new int[101][101];
    static int[][] dir = new int[][] { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) val[i][j] = MAX;
            val[0][0] = 0;

            for (int i = 0; i < N; i++) {
                String input = br.readLine();
                for (int j = 0; j < N; j++) {
                    map[i][j] = input.charAt(j) - '0';
                }
            }

            ArrayList<Pair_d8_3> queue = new ArrayList<>();
            queue.add(new Pair_d8_3(0, 0));
            while (!queue.isEmpty()) {
                Pair_d8_3 p = queue.remove(0);
                int x = p.first, y = p.second;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i][0], ny = y + dir[i][1];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        if (val[y][x] + map[ny][nx] < val[ny][nx]) {
                            val[ny][nx] = val[y][x] + map[ny][nx];
                            queue.add(new Pair_d8_3(nx, ny));
                        }
                    }
                }
            }

            bw.write("#" + test_case + " " + val[N - 1][N - 1] + '\n');
        }
        bw.flush();
	}
}