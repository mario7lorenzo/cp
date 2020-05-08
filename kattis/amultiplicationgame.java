import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		while(io.hasMoreTokens()) {
			long target = io.getLong();

			boolean is_stan = false;
			long curr = 1;
			while(curr < target) {
				if (is_stan) {
					curr *= 2;
				} else {
					curr *= 9;
				}
				is_stan = !is_stan;
			}

			if (!is_stan) {
				io.println("Ollie wins.");
			} else {
				io.println("Stan wins.");
			}
		}

		io.flush();
	}
}