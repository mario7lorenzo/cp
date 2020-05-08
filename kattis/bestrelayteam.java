import java.util.*;

class Triple {
	private String id;
	private double first;
	private double second;

	Triple(String id, double first, double second) {
		this.id = id;
		this.first = first;
		this.second = second;
	}

	public String getId() {
		return this.id;
	}

	public double getFirst() {
		return this.first;
	}

	public double getSecond() {
		return this.second;
	}
}

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();

		ArrayList<Triple> sorted_first = new ArrayList<Triple>();
		ArrayList<Triple> sorted_second = new ArrayList<Triple>();

		for (int i = 0; i < n; i++) {
			String name = io.getWord();
			double first = io.getDouble();
			double second = io.getDouble();
			sorted_first.add(new Triple(name, first, second));
			sorted_second.add(new Triple(name, first, second));
		} 

		Collections.sort(sorted_second, new Comparator<Triple>() {
			public int compare(Triple a, Triple b) {
				if (a.getSecond() - b.getSecond() < 0) {
					return -1;
				}
				return 1;
			}
		});

		Collections.sort(sorted_first, new Comparator<Triple>() {
			public int compare(Triple a, Triple b) {
				if (a.getFirst() - b.getFirst() < 0) {
					return -1;
				}
				return 1;
			}
		});

		ArrayList<String> lst = new ArrayList<String>();
		double total = 1000000.0;
		for (Triple t : sorted_first) {
			double time = t.getFirst();
			String name = t.getId();
			ArrayList<String> al = new ArrayList<String>();
			al.add(name);
			int counter = 1;
			for (Triple tt : sorted_second) {
				if (counter > 3) {
					break;
				}
				double times = tt.getSecond();
				String names = tt.getId();
				if (!name.equals(names)) {
					al.add(names);
					time += times;
					counter++;
				} 
			}
			if (time < total) {
				total = time;
				lst = al;
			}
		}
		io.println(total);
		for (String i : lst) {
			io.println(i);
		}
		io.flush();
	}
}