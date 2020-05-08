import java.util.*;

class Main {
	public static void main(String[] args) {
		int r, c;
		Kattio io = new Kattio(System.in);
		boolean isfirst = true;
		while (true) {
			r = io.getInt();
			c = io.getInt();
			if (r == 0 && c == 0) {
				break;
			}

			if (isfirst) {
				isfirst = false;
			} else {
				io.print('\n');
			}

			List<String> ori = new ArrayList<String>();
			List<String> transposed = new ArrayList<String>();
			for (int i = 0; i < r; i++) {
				ori.add(io.getWord());
			}

			for (int i = 0; i < c; i++) {
				String st = "";
				for (int j = 0; j < r; j++) {
					st += ori.get(j).charAt(i);
				}
				transposed.add(st);
			}

			// for (String i : transposed) {
			// 	io.println(i);
			// }

			Collections.sort(transposed, new Comparator<String>() {
				public int compare(String a, String b) {
					return a.compareToIgnoreCase(b);
				}
			});
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					io.print(transposed.get(j).charAt(i));
				}
				io.print('\n');
			}
		}
		io.flush();
	}
}