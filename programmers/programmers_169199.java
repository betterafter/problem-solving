import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(String[] board) {
        int answer = -1;
        int sx = 0, sy = 0;
        String[][] nb = new String[board.length][board[0].length()];
        int[][][] visited = new int[board.length][board[0].length()][1];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length(); j++) {
                nb[i][j] = Character.toString(board[i].charAt(j));
                if (nb[i][j].equals("R")) {
                    sx = j;
                    sy = i;
                }

                visited[i][j][0] = 0;
            }
        }
         
        Queue<int[]> q = new LinkedList<int[]>(); 
        q.add(new int[] { sx, sy, 0 } );
        int[][] dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; 
        while (!q.isEmpty()) {
            int[] val = q.remove();
            int x = val[0];
            int y = val[1];
            int cnt = val[2];

            if (nb[y][x].equals("G")) {
                return cnt;
            }

            for (int i = 0; i < dir.length; i++) {
                int[] npos = move(dir[i], new int[] { x, y }, nb);
                int nx = npos[0];
                int ny = npos[1];
                if (visited[ny][nx][0] == 0) {
                    visited[ny][nx][0] = cnt + 1;
                    q.add(new int[] { nx, ny, cnt + 1 } );
                }
            }
        }
        
        return answer;
    }

    int[] move(int[] dir, int[] curr, String[][] nb) {
        int[] result = new int[2];
        int cx = curr[0];
        int cy = curr[1];
        while (cx >= 0 && cx < nb[0].length && cy >=0 && cy < nb.length && !nb[cy][cx].equals("D")) {
            cx = cx + dir[0];
            cy = cy + dir[1];
        }

        result[0] = cx - dir[0];
        result[1] = cy - dir[1];
        return result;
    }
}