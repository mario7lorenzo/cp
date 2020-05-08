import java.util.*;

class Triple implements Comparable<Triple> {
    public int row;
    public int col;
    public int w;

    public Triple(int row, int col, int w) {
        this.row = row;
        this.col = col;
        this.w = w;
    }

    @Override
    public int compareTo(Triple another) {
    	return this.w - another.w;
    }
}

class Main {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);

        int r = io.getInt();
        int c = io.getInt();
        int inf = 1000000000;
        int[][] grid = new int[r][c];
        int[][] dist = new int[r][c];
        int[] move = new int[]{-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

        for (int i = 0; i < r; i++) {
            String ln = io.getWord();

            for (int j = 0; j < c; j++) {
                grid[i][j] = Character.getNumericValue(ln.charAt(j));
            }
        }

        int n = io.getInt();
        for (int k = 0; k < n; k++) {

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    dist[i][j] = inf;
                }
            }

            int r1 = io.getInt() - 1;
            int c1 = io.getInt() - 1;
            int r2 = io.getInt() - 1;
            int c2 = io.getInt() - 1;

            PriorityQueue<Triple> q = new PriorityQueue<>();
            q.add(new Triple(r1, c1, 0));
            dist[r1][c1] = 0;

            while (!q.isEmpty()) {
                Triple coor = q.peek();
                q.remove();
            
                int x = coor.row;
                int y = coor.col;
                int w = coor.w;

                if (w > dist[x][y]) {
                	continue;
                }

                for (int i = 0; i < 8; i++) {
                	int next_r = x + move[2*i];
                	int next_c = y + move[2*i + 1];
                	int tot = w + (i == grid[x][y] ? 0 : 1);

                	if (next_r >= 0 && next_r < r && next_c >= 0 && next_c < c && dist[next_r][next_c] > tot) {
                		q.add(new Triple(next_r, next_c, tot));
                		dist[next_r][next_c] = tot;
                	}
                }
            }

            io.println(dist[r2][c2]);
        }

        io.flush();
    }
}