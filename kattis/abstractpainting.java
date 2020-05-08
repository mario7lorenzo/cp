import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int tc = io.getInt();
		long mod = (long)(1E9+7);

		while (tc-- > 0) {
			int r = io.getInt();
			int c = io.getInt();

			int cr = r * c;

			long tot = 1;
			for (int i = 0; i < cr; i++) {
				tot *= 2;
				tot %= mod;
			}

			for (int i = 0; i < c + r; i++) {
				tot *= 3;
				tot %= mod;
			}

			io.println(tot);
			io.flush();
		}
	}
}