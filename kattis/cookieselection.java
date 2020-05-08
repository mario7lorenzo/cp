import java.util.*;

class Main {
	public static PriorityQueue<Long> lhs = new PriorityQueue<Long>(Collections.reverseOrder());
	public static PriorityQueue<Long> rhs = new PriorityQueue<Long>();

	public static void adjust() {
		if (lhs.size() - rhs.size() == 2) {
			long x = lhs.poll();
			rhs.add(x);
		} else if (rhs.size() - lhs.size() == 1) {
			long y = rhs.poll();
			lhs.add(y);
		}
	}

	public static void main(String[] args) {
		
		Kattio io = new Kattio(System.in);
		int curr_size = 0;

		while (io.hasMoreTokens()) {
			String val = io.getWord();

			if (val.equals("#")) {
				if (curr_size%2 == 0) {
					io.println(rhs.poll());
				} else {
					io.println(lhs.poll());
				}
				curr_size--;

			} else {
				long value = Long.parseLong(val);
				if (curr_size == 0) {
					lhs.add(value);
				} else if (curr_size == 1) {
					if (lhs.peek() > value) {
						rhs.add(lhs.poll());
						lhs.add(value);
					} else {
						rhs.add(value);
					}
				} else {
					long left_biggest = lhs.peek();
					long right_smallest = rhs.peek();
					if (value < left_biggest) {
						lhs.add(value);
					} else {
						rhs.add(value);
					}
					adjust();
				}
				curr_size++;
			}
		}
		io.flush();
	}
}