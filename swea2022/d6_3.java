package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Pair_d6_3<T, E> {
    int first;
    int second;
    public Pair_d6_3(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution_d6_3
{
    static int N, res, len, mcpu;
    static int[][] map = new int[13][13];
    static int[][] dir = new int[][] { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    static int[][] visit = new int[13][13];
    static ArrayList<Pair_d6_3> cpu = new ArrayList<>();

    static boolean isConnect(int x, int y, int[][] cmap, int dir) {
        switch (dir) {
            case 1 : 
                for (int i = 0; i < x; i++) {
                    if (cmap[y][i] == 1 || cmap[y][i] == 2) return false;
                }
                break;
            case 2 :
                for (int i = y - 1; i >= 0; i--) {
                    if (cmap[i][x] == 1 || cmap[i][x] == 2) return false;
                }
                break;
            case 3 :
                for (int i = x + 1; i < N; i++) {
                    if (cmap[y][i] == 1 || cmap[y][i] == 2) return false;
                }
                break;
            case 4 :
                for (int i = y + 1; i < N; i++) {
                    if (cmap[i][x] == 1 || cmap[i][x] == 2) return false;
                }
                break;
        }
        return true;
    }

    static void connect(int x, int y, int[][] cmap, int dir) {
        switch (dir) {
            case 1 : 
                for (int i = 0; i < x; i++) {
                    cmap[y][i] = 2;
                    len++;
                }
                break;
            case 2 :
                for (int i = y - 1; i >= 0; i--) {
                    cmap[i][x] = 2;
                    len++;
                }
                break;
            case 3 :
                for (int i = x + 1; i < N; i++) {
                    cmap[y][i] = 2;
                    len++;
                }
                break;
            case 4 :
                for (int i = y + 1; i < N; i++) {
                    cmap[i][x] = 2;
                    len++;
                }
                break;
        }
    }

    static void disconnect(int x, int y, int[][] cmap, int dir) {
        switch (dir) {
            case 1 : 
                for (int i = 0; i < x; i++) {
                    cmap[y][i] = 0;
                    len--;
                }
                break;
            case 2 :
                for (int i = y - 1; i >= 0; i--) {
                    cmap[i][x] = 0;
                    len--;
                }
                break;
            case 3 :
                for (int i = x + 1; i < N; i++) {
                    cmap[y][i] = 0;
                    len--;
                }
                break;
            case 4 :
                for (int i = y + 1; i < N; i++) {
                    cmap[i][x] = 0;
                    len--;
                }
                break;
        }
    }

    static void dfs(int[][] cmap, int idx, int cpus) {
        if (idx >= cpu.size()) {
            if (mcpu < cpus) {
                mcpu = cpus;
                res = len;
            } else if (mcpu == cpus) {
                res = Math.min(res, len);
            }
            return;
        }

        int x = cpu.get(idx).first;
        int y = cpu.get(idx).second;
        for (int i = 1; i <= 4; i++) {
            if (isConnect(x, y, cmap, i)) {
                connect(x, y, cmap, i);
                dfs(cmap, idx + 1, cpus + 1);
                disconnect(x, y, cmap, i);
            }
        }
        dfs(cmap, idx + 1, cpus);
    }
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            N = Integer.parseInt(br.readLine());
            res = 1000000;
            mcpu = 0;
            cpu.clear();
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                for (int j = 0; j < N; j++) {
                    int ele = Integer.parseInt(input[j]);
                    if (ele == 1 && i != 0 && j != 0) {
                        cpu.add(new Pair_d6_3(j, i));
                    }
                    map[i][j] = ele;
                }
            }
            dfs(map, 0, 0);
            System.out.println("#" + test_case + " " + res);
 		}
	}
}