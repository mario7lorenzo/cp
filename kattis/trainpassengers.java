import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		long c = io.getLong();
		int n = io.getInt();
		
		boolean possible = true;

		long curr_pass = 0;
		for (int i = 0; i < n; i++) {
			long l, e, s;
			l = io.getLong();
			e = io.getLong();
			s = io.getLong();

			curr_pass -= l;
			if (curr_pass < 0) {
				possible = false;
				break;
			} 

			curr_pass += e;
			if (curr_pass > c || curr_pass < 0 || (c - curr_pass > 0 && s > 0)) {
				possible = false;
				break;
			}
		}

		if (curr_pass != 0) {
			possible = false;
		}

		if (possible) {
			io.println("possible");
		} else {
			io.println("impossible");
		}
		io.flush();
	}
}