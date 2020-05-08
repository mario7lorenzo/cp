import java.util.*;

class Triplet implements Comparable<Triplet> {
	private int first;
	private int second;
	private int third;

	Triplet(int first, int second, int third) {
		this.first = first;
		this.second = second;
		this.third = third;
	}

	public int getFirst() {
		return this.first;
	}

	public int getSecond() {
		return this.second;
	}

	public int getThird() {
		return this.third;
	}

	@Override
	public String toString() {
		return "(" + this.first + ", " + this.second + ", " + this.third + ")";
	}

	@Override
	public int compareTo(Triplet b) {
		int first_sel = this.getFirst() - b.getFirst();
		if (first_sel != 0) {
			return first_sel;
		} 
		int second_sel = this.getSecond() - b.getSecond();
		if (second_sel != 0) {
			return second_sel;
		}
		return this.getThird() - b.getThird();
	}
}

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();
		int k = io.getInt();

		List<Triplet> lst = new ArrayList<Triplet>();
		TreeSet<Triplet> tset = new TreeSet<Triplet>();

		// Triplet elems: (100 * val + interest * day), val, day
		for (int i = 1; i <= n; i++) {
			int val = io.getInt();
			Triplet trip = new Triplet(((100 * val) + (k * i)), val, i);
			tset.add(trip);
			lst.add(trip);
		}

		int maxi = -1;
		int counter = 0;
		for (Triplet curr_trip : lst) {
			Triplet mini_trip = tset.first();
			maxi = Math.max(maxi, (curr_trip.getSecond() * 100) - mini_trip.getFirst() + (counter * k));
			// remove triplet from set
			tset.remove(curr_trip);
			counter++;
		}
		if (maxi < 0) {
			io.println(0);
		}  else {
			io.println(maxi);
		}
		io.flush();
	}
}