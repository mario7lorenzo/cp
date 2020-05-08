class Main {
	static int[] monkey_one_a, monkey_one_b, monkey_two_c, monkey_two_d;
	static int t, n, m;
	static long[] calculate(int ta) {
		long monkey_a = 0, monkey_b = 0;
		
		for (int i = 0; i < n; i++) {
			int a = monkey_one_a[i];
			int b = monkey_one_b[i];
			if (ta >= a) {
				monkey_a += ((ta - a) / b) + 1;
			}
		}

		for (int i = 0; i < m; i++) {
			int c = monkey_two_c[i];
			int d = monkey_two_d[i];
			int tc = t - ta;
			if (tc >= c) {
				monkey_b += ((tc - c) / d) + 1;
			}
		}

		return new long[]{monkey_a, monkey_b};
	}

	static int binary_search(int a, int b) {
		int mid = a + ((b - a) / 2);
		long[] result = calculate(mid);
		long[] result_plus_one = calculate(mid + 1);
		long monkey_a = result[0];
		long monkey_b = result[1];
		long monkey_next_a = result_plus_one[0];
		long monkey_next_b = result_plus_one[1];
		// System.out.println("mid");
		// System.out.println(mid);
		// System.out.println("a");
		// System.out.println(monkey_a);
		// System.out.println("b");
		// System.out.println(monkey_b);
		
		// check if change sign

		if ( ( ((monkey_a - monkey_b) < 0) && (monkey_next_a - monkey_next_b) > 0 ) || ( ((monkey_a - monkey_b) > 0) && (monkey_next_a - monkey_next_b) < 0 ) ) {
			if ((monkey_a - monkey_b) < 0) {
				return mid;
			} else {
				return mid + 1;
			}
		}
		if (monkey_a > monkey_b) {
			return binary_search(a, mid - 1);
		} else if (monkey_a < monkey_b) {
			return binary_search(mid + 1, b);
		} else {
			return mid;
		}

	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		t = io.getInt();
		n = io.getInt();

		monkey_one_a = new int[n];
		monkey_one_b = new int[n];
		for (int i = 0; i < n; i++) {
			monkey_one_a[i] = io.getInt();
			monkey_one_b[i] = io.getInt();
		}

		m = io.getInt();
		monkey_two_c = new int[m];
		monkey_two_d = new int[m];
		for (int i = 0; i < m; i++) {
			monkey_two_c[i] = io.getInt();
			monkey_two_d[i] = io.getInt();
		}

		// for (int i = 1; i <= t; i++) {
		// 	long[] arr = calculate(i);
		// 	io.println(arr[0] - arr[1]);
		// }
		io.println(binary_search(1, t));
		io.flush();
	}
}