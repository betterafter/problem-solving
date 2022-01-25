package swea2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Pair_d6_2<T, E> {
    int x;
    int y;

    public Pair_d6_2(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Node_d6_2<T> {
    Pair_d6_2<Integer, Integer> data;
    Node_d6_2<T> next;
    Node_d6_2<T> prev;

    public Node_d6_2(Pair_d6_2<Integer, Integer> data) {
        this.data = data;
    }
}

class UserSolution_d6_2 {

    boolean visit[][] = new boolean[12][12];
    int map[][] = new int[12][12];
    int val[][] = new int[12][12];
    int[][] dir = new int[][] { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int mapsize;
    int MAX = 10000000;

    void bfs_init(int map_size, int map[][]) {
        this.mapsize = map_size;
        for (int i = 1; i <= map_size; i++) {
            for (int j = 1; j <= map_size; j++) {
                this.map[i][j] = map[i - 1][j - 1];
            }
        }
    }

    int bfs(int x1, int y1, int x2, int y2) {

        for (int i = 1; i <= mapsize; i++) {
            for (int j = 1; j <= mapsize; j++) {
                this.val[i][j] = MAX;
                this.visit[i][j] = false;
            }
        }

        Node_d6_2<Pair_d6_2<Integer, Integer> > head = new Node_d6_2<Pair_d6_2<Integer, Integer> >(new Pair_d6_2<Integer, Integer>(-1, -1));
        Node_d6_2<Pair_d6_2<Integer, Integer> > tail = new Node_d6_2<Pair_d6_2<Integer, Integer> >(new Pair_d6_2<Integer, Integer>(-1, -1));
        head.next = tail;
        tail.prev = head;

        Node_d6_2 curr = new Node_d6_2<Pair_d6_2>(new Pair_d6_2<Integer, Integer>(x1, y1));
        curr.prev = head;
        curr.next = tail;
        head.next = curr;
        tail.prev = curr;
        visit[y1][x1] = true;
        val[y1][x1] = 0;

        while (head.next.data.x != -1) {
            curr = head.next;
            int x = curr.data.x;
            int y = curr.data.y;
            curr.next.prev = head;
            head.next = curr.next;
            if (x == x2 && y == y2) continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 1 && nx <= this.mapsize && ny >= 1 && ny <= this.mapsize && map[ny][nx] == 0) {
                    if (val[ny][nx] > val[y][x] + 1) {
                        visit[ny][nx] = true;
                        val[ny][nx] = val[y][x] + 1;
                        
                        Node_d6_2 n = new Node_d6_2<Pair_d6_2>(new Pair_d6_2<Integer, Integer>(nx, ny));
                        n.prev = tail.prev;
                        n.next = tail;
                        tail.prev.next = n;
                        tail.prev = n;
                    }
                }
            }
        }

    	return val[y2][x2] == MAX ? -1 : val[y2][x2];
    }	
}


class Solution_d6_2 {
	
	private final static UserSolution_d6_2 usersolution = new UserSolution_d6_2();
	
	private static BufferedReader br;
	
	private static int cmd_bfs() throws Exception {
		
		int score = 100;
		int N, M, x1, y1, x2, y2, dist, ans;
		int[][] map = new int[10][10];
		String str;
		StringTokenizer st;
		
		br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();
		N = Integer.parseInt(str);
		
		for(int i = 0; i < N; i++) {
			str = br.readLine();
			st = new StringTokenizer(str, " ");
			for(int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		usersolution.bfs_init(N, map);
		
		str = br.readLine();
		M = Integer.parseInt(str);
		
		for(int i = 1; i <= M; i++) {
			str = br.readLine();
			st = new StringTokenizer(str, " ");
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());
			ans = Integer.parseInt(st.nextToken());
			
			dist = usersolution.bfs(x1, y1, x2, y2);
            System.out.println(dist);

			if(dist != ans) {
				score = 0;
			}
		}
		return score;
	}
	
	public static void main(String[] args) throws Exception {
		System.out.println("#total score : " + cmd_bfs());
	}
}