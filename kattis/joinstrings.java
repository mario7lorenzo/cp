import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();
		int inf = 1000000000;
		String[] arr = new String[100010];
		int[] nodelst = new int[100010];
		boolean[] boolarr = new boolean[100010];
		HashMap<Integer, Integer> al = new HashMap<>();

		for (int i = 1; i <= n; i++) {
			String c = io.getWord();
			arr[i] = c;
			nodelst[i] = i;
			al.put(i, inf);
			boolarr[i] = true;
		}

		for (int i = 1; i <= n - 1; i++) {
			int a = io.getInt();
			int b = io.getInt();
			int temp = nodelst[a];
			nodelst[a] = nodelst[b];
			boolarr[b] = false;
			al.put(temp, b);
		}

		int k = -1;
		for (int i = 1; i <= n; i++) {
			if (boolarr[i]) {
				k = i;
				break;
			}
		}

		while (true) {
			io.print(arr[k]);
			if (al.get(k) == inf) {
				break;
			}
			else {
				k = al.get(k);
			}
		}

		io.print('\n');
		io.flush();
	}
}