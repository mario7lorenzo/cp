import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		int n = io.getInt();

		ArrayList<Double> al = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			String gapenting = io.getWord();
			double p = io.getDouble();

			al.add(p);
		}

		Collections.sort(al, Collections.reverseOrder());

		double result = 0;
		for (int i = 1; i <= n; i++) {
			result += i * al.get(i-1);
		}

		io.println(result);
		io.flush();
	}
}