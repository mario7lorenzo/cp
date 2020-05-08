import java.util.*;

class Pair {
	public int first;
	public int second;

	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public String toString() {
		return this.first + " " + this.second;
	}
}

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		int r = io.getInt();
		int c = io.getInt();
		char[][] grid = new char[r][c];
		boolean[][] is_visited = new boolean[r * c][120];
		boolean[][] safe_cells_per_turn = new boolean[120][r * c]; 

		for (int i = 0; i < 120; i++) {
			for (int j = 0; j < r * c; j++) {
				safe_cells_per_turn[i][j] = true;
			}
		}

		String bed_r = io.getWord().substring(1);
		String bed_c = io.getWord();
		bed_c = bed_c.substring(0, bed_c.length() - 1);
		String fridge_r = io.getWord().substring(1);
		String fridge_c = io.getWord();
		fridge_c = fridge_c.substring(0, fridge_c.length() - 1);

		int r_bed = Integer.parseInt(bed_r) - 1;
		int c_bed = Integer.parseInt(bed_c) - 1;
		int r_fridge = Integer.parseInt(fridge_r) - 1;
		int c_fridge = Integer.parseInt(fridge_c) - 1;

		int hash_bed = r_bed * c + c_bed;
		int hash_fridge = r_fridge * c + c_fridge;


		for (int i = 0; i < r; i++) {
			String ln = io.getWord();

			for (int j = 0; j < c; j++) {
				
				for (int k = 0; k < 120; k++) {
					is_visited[(i * c) + j][k] = false;
				}

				grid[i][j] = ln.charAt(j);
				if (grid[i][j] == '#') {
					for (int k = 0; k < 120; k++) {
						safe_cells_per_turn[k][(i * c) + j] = false;
					}
				}
			}

		}

		int guard = io.getInt();
		for (int i = 0 ; i < guard; i++) {
			int turns = io.getInt();
			ArrayList<Integer> coor = new ArrayList<>(); 
			
			for (int j = 0; j < turns; j++) {
				String guard_r = io.getWord().substring(1);
				String guard_c = io.getWord();
				guard_c = guard_c.substring(0, guard_c.length() - 1);
				int r_guard = Integer.parseInt(guard_r) - 1;
				int c_guard = Integer.parseInt(guard_c) - 1;
				int hashed_guard = (r_guard * c) + c_guard;
				coor.add(hashed_guard);
			}

			ArrayList<Integer> fin = new ArrayList<>(coor);
			for (int j = coor.size() - 2; j >= 1; j--) {
				fin.add(coor.get(j));
			}

			for (int j = 0; j < 120; j++) {
				int val = fin.get(j % fin.size());
				int r_val = val / c;
				int c_val = val % c;

				// his own point
				safe_cells_per_turn[j][val] = false;

				// up until hit wall
				int r_curr = r_val - 1;
				int c_curr = c_val;
				while (r_curr >= 0 && r_curr < r && c_curr >= 0 && c_curr < c)  {
					if (grid[r_curr][c_curr] == '#') {
						break;
					}
					int hashed = (r_curr * c) + c_curr;

					safe_cells_per_turn[j][hashed] = false;
					r_curr--;
				}

				// down until hit wall
				r_curr = r_val + 1;
				c_curr = c_val;
				while (r_curr >= 0 && r_curr < r && c_curr >= 0 && c_curr < c)  {
					if (grid[r_curr][c_curr] == '#') {
						break;
					}
					int hashed = (r_curr * c) + c_curr;

					safe_cells_per_turn[j][hashed] = false;
					r_curr++;
				}

				// left until hit wall
				r_curr = r_val;
				c_curr = c_val - 1;

				while (r_curr >= 0 && r_curr < r && c_curr >= 0 && c_curr < c)  {
					if (grid[r_curr][c_curr] == '#') {
						break;
					}
					int hashed = (r_curr * c) + c_curr;
					safe_cells_per_turn[j][hashed] = false;
					c_curr--;
				}

				// right until hit wall
				r_curr = r_val;
				c_curr = c_val + 1;
				while (r_curr >= 0 && r_curr < r && c_curr >= 0 && c_curr < c)  {
					if (grid[r_curr][c_curr] == '#') {
						break;
					}
					int hashed = (r_curr * c) + c_curr;

					safe_cells_per_turn[j][hashed] = false;
					c_curr++;
				}
			}
		}

		for (int i = 0; i < 120; i++) {
			safe_cells_per_turn[i][hash_fridge] = true;
		}

		if (hash_bed == hash_fridge) {
			io.println(0);
		} else if (!safe_cells_per_turn[0][hash_bed]) {
			io.println("IMPOSSIBLE");
		} else {
			Queue<Pair> q = new LinkedList<>();
			boolean is_impossible = true;
			q.add(new Pair(hash_bed, 0));
			is_visited[hash_bed][0] = true;

			while (!q.isEmpty()) {
				Pair coor = q.peek();
				q.remove();
				// io.println(coor);
				int val = coor.first;
				int turns = coor.second;
				if (val == hash_fridge) {
					io.println(turns);
					is_impossible = false;
					break;
				}

				int r_val = val / c;
				int c_val = val % c;
				int next_turn = (turns + 1) % 120;

				// stand still
				if (!is_visited[val][next_turn] && safe_cells_per_turn[next_turn][val]) {
					q.add(new Pair(val, turns + 1));
					is_visited[val][next_turn] = true;
				}

				// up
				if (r_val - 1 >= 0 && r_val - 1 < r && c_val >= 0 && c_val < c) {
					if (!is_visited[val - c][next_turn] && safe_cells_per_turn[next_turn][val - c]) {
						q.add(new Pair(val - c, turns + 1));
						is_visited[val - c][next_turn] = true;
					}
				}

				// down
				if (r_val + 1 >= 0 && r_val + 1 < r && c_val >= 0 && c_val < c) {
					if (!is_visited[val + c][next_turn] && safe_cells_per_turn[next_turn][val + c]) {
						q.add(new Pair(val + c, turns + 1));
						is_visited[val + c][next_turn] = true;
					}
				}

				// left
				if (r_val >= 0 && r_val < r && c_val - 1 >= 0 && c_val - 1 < c) {
					if (!is_visited[val - 1][next_turn] && safe_cells_per_turn[next_turn][val - 1]) {
						q.add(new Pair(val - 1, turns + 1));
						is_visited[val - 1][next_turn] = true;
					}
				}

				// right
				if (r_val >= 0 && r_val < r && c_val + 1 >= 0 && c_val + 1 < c) {
					if (!is_visited[val + 1][next_turn] && safe_cells_per_turn[next_turn][val + 1]) {
						q.add(new Pair(val + 1, turns + 1));
						is_visited[val + 1][next_turn] = true;
					}
				}
			}

			if (is_impossible) {
				io.println("IMPOSSIBLE");
			}
		}

		io.flush();
	}
}