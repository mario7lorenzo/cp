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
		int first_sel = b.getFirst() - this.getFirst();
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
        int m = io.getInt();

        Triplet[] hashmap = new Triplet[n + 1];
        TreeSet<Triplet> tset = new TreeSet<Triplet>();

        for (int i = 1; i <= n; i++) {
            Triplet trip = new Triplet(0, 0, i);
            tset.add(trip);
            hashmap[i] = trip;
        }

        int curr = 0;
        for (int i = 0; i < m; i++) {
            int t = io.getInt();
            int p = io.getInt();

            Triplet curr_trip = hashmap[t];
            int prev_solved = curr_trip.getFirst();
            int prev_pen = curr_trip.getSecond();
            int curr_solved = prev_solved + 1;
            int curr_pen = prev_pen + p;
            
            if (t == 1) {
            	curr -= tset.subSet(new Triplet(curr_solved, curr_pen, t), false, curr_trip, false).size();
            } else {
            	boolean inc = hashmap[1].compareTo(curr_trip) < 0 && hashmap[1].compareTo(new Triplet(curr_solved, curr_pen, t)) > 0;
            	if (inc) {
            		curr++;
            	}
            }
            tset.remove(curr_trip);
            Triplet another_trip = new Triplet(curr_solved, curr_pen, t);
            tset.add(another_trip);
            hashmap[t] = another_trip;
            io.println(curr + 1);
        }

        io.flush();
    }
}