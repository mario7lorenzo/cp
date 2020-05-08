import java.util.*;

class Main {
	public static void main(String[] args) {
		long mod = 1000000007;
		Kattio io = new Kattio(System.in);

		int v = io.getInt();
		int e = io.getInt();
		int q = io.getInt();
		boolean is_complement = false;
		boolean is_transposed = false;

		int[][] adj_matrix = new int[4005][4005];
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				adj_matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < e; i++) {
			int a = io.getInt();
			int b = io.getInt();
			adj_matrix[a][b] = 1;
		}

		for (int k = 0; k < q; k++) {
			int command = io.getInt();

			if (command == 1) {
				if (!is_complement) {
					for (int i = 0; i < v; i++) {
						adj_matrix[i][v] = 0;
						adj_matrix[v][i] = 0;
					}
				} else {
					for (int i = 0; i < v; i++) {
						adj_matrix[i][v] = 1;
						adj_matrix[v][i] = 1;
					}
				}
				adj_matrix[v][v] = 0;
				v++;
			} else if (command == 2) {
				int a = io.getInt();
				int b = io.getInt();

				if (is_transposed && is_complement) {
					adj_matrix[b][a] = 0;
				} else if (is_transposed) {
					adj_matrix[b][a] = 1;
				} else if (is_complement) {
					adj_matrix[a][b] = 0;
				} else {
					adj_matrix[a][b] = 1;
				}
			} else if (command == 3) {
				int x = io.getInt();
				if (!is_complement) {
					for (int i = 0; i < v; i++) {
						if (i != x) {
							adj_matrix[i][x] = 0;
							adj_matrix[x][i] = 0;
						}
					}
				} else {
					for (int i = 0; i < v; i++) {
						if (i != x) {
							adj_matrix[i][x] = 1;
							adj_matrix[x][i] = 1;
						}
					}
				}
			} else if (command == 4) {
				int a = io.getInt();
				int b = io.getInt();

				if (is_transposed && is_complement) {
					adj_matrix[b][a] = 1;
				} else if (is_transposed) {
					adj_matrix[b][a] = 0;
				} else if (is_complement) {
					adj_matrix[a][b] = 1;
				} else {
					adj_matrix[a][b] = 0;
				}
			} else if (command == 5) {
				is_transposed = !is_transposed;
			} else {
				is_complement = !is_complement;
			}
		}

		io.println(v);
		if (is_complement && is_transposed) {
			for (int i = 0; i < v; i++) {
				long hash_value = 0;
				int counter = 0;

				for (int j = v-1; j >= 0; j--) {
					if (i != j && adj_matrix[j][i] == 0) {
						hash_value = (hash_value * 7 + j) % mod;
						counter++;
					}
				}
				io.println(counter + " " + hash_value);
			}
		} else if (is_transposed) {
			for (int i = 0; i < v; i++) {
				long hash_value = 0;
				int counter = 0;

				for (int j = v-1; j >= 0; j--) {
					if (i != j && adj_matrix[j][i] == 1) {
						hash_value = (hash_value * 7 + j) % mod;
						counter++;
					}
				}
				io.println(counter + " " + hash_value);
			}
		} else if (is_complement) {
			for (int i = 0; i < v; i++) {
				long hash_value = 0;
				int counter = 0;

				for (int j = v-1; j >= 0; j--) {
					if (i != j && adj_matrix[i][j] == 0) {
						hash_value = (hash_value * 7 + j) % mod;
						counter++;
					}
				}
				io.println(counter + " " + hash_value);
			}
		} else {
			for (int i = 0; i < v; i++) {
				long hash_value = 0;
				int counter = 0;

				for (int j = v-1; j >= 0; j--) {
					if (i != j && adj_matrix[i][j] == 1) {
						hash_value = (hash_value * 7 + j) % mod;
						counter++;
					}
				}
				io.println(counter + " " + hash_value);
			}
		}

		io.flush();
	}
}