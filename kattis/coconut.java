import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		HashSet<Integer> still_play = new HashSet<>();
		Deque<Integer> q = new LinkedList<>();
		int s = io.getInt();
		int n = io.getInt();
		boolean[] is_cracked = new boolean[n];
		boolean[] is_down = new boolean[2 * n];
		int[] num_hands = new int[n];

		for (int i = 0; i < n; i++) {
			still_play.add(i);
			q.add(2 * i);
			is_cracked[i] = false;
			is_down[i] = false;
			num_hands[i] = 2;
		}

		while (still_play.size() > 1) {
			for (int i = 1; i < s; i++) {
				int x = q.peek();
				q.removeFirst();
				q.add(x);
			}

			int curr = q.peek();
			if (!is_cracked[curr / 2]) {
				q.removeFirst();
				q.addFirst(curr + 1);
				q.addFirst(curr);
				is_cracked[curr / 2] = true; 
			} else if (!is_down[curr]) {
				q.remove();
				q.add(curr);
				is_down[curr] = true;
			} else {
				q.remove();
				num_hands[curr/2]--;
				if (num_hands[curr/2] == 0) {
					still_play.remove(curr/2);
				}
			}
		}

		Iterator itr = still_play.iterator();
		int result = -5;
		while (itr.hasNext()) {
			result = (int)itr.next();
		}

		io.println(result + 1);
		io.flush();
	}
}