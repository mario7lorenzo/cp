import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		int easy = io.getInt();
		int medium = io.getInt();
		int hard = io.getInt();
		int n = io.getInt();

		if (easy < 1 || medium < 1 || hard < 1 || (easy + medium + hard < n)) {
			io.println("NO");
		} else {
			io.println("YES");
		}

		io.flush();
	}
}