import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);

		int n = io.getInt();
		int q = io.getInt();

		UFDS ufds = new UFDS(n);
		while (q-- > 0) {
			String command = io.getWord();

			if (command.charAt(0) == '?') {
				io.println(ufds.isSameSet(io.getInt(), io.getInt()) ? "yes" : "no");
			} else {
				ufds.unionSet(io.getInt(), io.getInt());
			}
		}

		io.flush();
	}
}