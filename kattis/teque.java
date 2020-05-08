import java.util.*;

class Main {
	public static int[] first_half = new int[2000003];
	public static int[] second_half = new int[2000003];
	public static Integer first_half_first = null;
	public static Integer first_half_last = null;
	public static Integer second_half_first = null;
	public static Integer second_half_last = null;

	public static void adjust() {
		int sz1, sz2;
		if (first_half_last == null || first_half_first == null) {
			sz1 = 0;
			sz2 = second_half_last - second_half_first + 1;
			if (sz2 - sz1 == 1) {
				first_half_first = 1000000;
				first_half_last = 1000000;
				int x = second_half[second_half_first];
				first_half[first_half_last] = x;
				second_half_first++;
			}
		} else if (second_half_first == null || second_half_last == null) {
			sz2 = 0;
			sz1 = first_half_last - first_half_first + 1;
			if (sz1 - sz2 == 2) {
				second_half_first = 1000000;
				second_half_last = 1000000;
				int x = first_half[first_half_last];
				second_half[second_half_first] = x;
				first_half_last--;
			}
		} else {
			sz1 = first_half_last - first_half_first + 1;
			sz2 = second_half_last - second_half_first + 1;
			if (sz1 - sz2 == 2) {
				second_half_first--;
				int x = first_half[first_half_last];
				second_half[second_half_first] = x;
				first_half_last--;
			} else if (sz2 - sz1 == 1) {
				first_half_last++;
				int x = second_half[second_half_first];
				first_half[first_half_last] = x;
				second_half_first++;
			}
		}
		
	}

	public static int getTeque(int ind) {
		int sz1 = first_half_last - first_half_first + 1;
		if (ind < sz1) {
			return first_half[first_half_first + ind];
		} else {
			return second_half[second_half_first + ind - sz1];
		}
	}

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int queries = io.getInt();
		for (int i = 0; i < queries; i++) {
			String command = io.getWord();
			if (command.equals("push_back")) {
				if (second_half_last == null) {
					second_half_last = 1000000;
					second_half_first = 1000000;
					second_half[second_half_last] = io.getInt();
				} else {
					second_half_last++;
					second_half[second_half_last] = io.getInt();
				}
			} else if (command.equals("push_front")) {
				if (first_half_first == null) {
					first_half_first = 1000000;
					first_half_last = 1000000;
					first_half[first_half_first] = io.getInt();
				} else {
					first_half_first--;
					first_half[first_half_first] = io.getInt();
				}
			} else if (command.equals("push_middle")) {
				if (first_half_last == null) {
					first_half_first = 1000000;
					first_half_last = 1000000;
					first_half[first_half_last] = io.getInt();
				} else {
					first_half_last++;
					first_half[first_half_last] = io.getInt();
				}
			} else {
				int ind = io.getInt();
				io.println(getTeque(ind));
			}
			adjust();
		}

		io.flush();
	}
}