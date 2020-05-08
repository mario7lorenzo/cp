import java.util.*;

class Pair {
	public int first;
	public int second;

	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public String toString() {
		return "[" + this.first + ", " + this.second + "]";
	}
}

class Main {
	public static int r, c;
	public static int[][] grid;
	public static int[] colors;
	public static int[] arr = new int[1000050];
	public static int curr_color = 2;

	public static boolean canReach(int a, int b) {
		return a >= 0 && a < r && b >= 0 && b < c;
	}
	
	public static void bfs(Pair from) {
        Queue<Pair> q = new LinkedList<>();
        q.add(from);

        boolean found = false;
        while (!q.isEmpty()) {
            Pair coor = q.peek();
            q.remove();
            if (grid[coor.first][coor.second] == 0 || grid[coor.first][coor.second] == 1) {
            	int hv = (c * coor.first) + coor.second;
	            if (canReach(coor.first - 1, coor.second)) {
	            	if (arr[hv] == arr[hv - c]) {
	                	q.add(new Pair(coor.first - 1, coor.second));
	            	}
	            }

	            if (canReach(coor.first + 1, coor.second)) {
	            	if (arr[hv] == arr[hv + c]) {
	                	q.add(new Pair(coor.first + 1, coor.second));
	            	}
	            }

	            if (canReach(coor.first, coor.second - 1)) {
	            	if (arr[hv] == arr[hv - 1]) {
	                    q.add(new Pair(coor.first, coor.second - 1));
	            	}
	            }

	            if (canReach(coor.first, coor.second + 1)) {
	            	if (arr[hv] == arr[hv + 1]) {
	                	q.add(new Pair(coor.first, coor.second + 1));
	            	}
	            }

	            grid[coor.first][coor.second] = curr_color;
	        }
        }

        curr_color++;
    }

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		r = io.getInt();
		c = io.getInt();
		grid = new int[r][c];

		for (int i = 0; i < r; i++) {
			String ln = io.getWord();

			for (int j = 0; j < c; j++) {
				grid[i][j] = Character.getNumericValue(ln.charAt(j));
				arr[(c * i) + j] = grid[i][j];
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == 0 || grid[i][j] == 1) {
					bfs(new Pair(i, j));
				}
			}
		}

		int tc = io.getInt();

		for (int i = 0; i < tc; i++) {
			int r1 = io.getInt() -1;
			int c1 = io.getInt() - 1;
			int r2 = io.getInt() - 1;
			int c2 = io.getInt() -1;

			if (grid[r1][c1] == grid[r2][c2]) {
				if (arr[(c * r1) + c1] == 1) {
					io.println("decimal");
				} else {
					io.println("binary");
				}
			} else {
				io.println("neither");
			}
			
		}

		io.flush();
	}
}