import java.util.*;

class Main {
	public static long calculateScore(String classes) {
		String[] lst = classes.split("-");
		long counter = 0;
		long multiplier = 100000000000L;
		int curr = lst.length;
		while (curr > 0) {
			if (lst[curr - 1].equals("middle")) {
				counter += multiplier * 2;
			} else if (lst[curr - 1].equals("upper")) {
				counter += multiplier * 5;
			} else {
				counter += multiplier;
			}

			multiplier /= 10;
			curr--;
		}
		curr = 10 - lst.length;
		while (curr > 0) {
			counter += multiplier * 2;
			curr--;
			multiplier /= 10;
		}
		return -counter;
	}
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int tc = io.getInt();
		for (int i = 0; i < tc; i++) {
			int ln = io.getInt();
			List<String[]> lst = new ArrayList<String[]>();
			for (int j = 0; j < ln; j++) {
				String name = io.getWord();
				String class_train = io.getWord();
				String dummy = io.getWord();
				name = name.substring(0, name.length() - 1);
				lst.add(new String[]{name, class_train});
			}
			Collections.sort(lst, new Comparator<String[]>() {
				public int compare(String[] a, String[] b) {
					return a[0].compareTo(b[0]);
				}
			});

			Collections.sort(lst, new Comparator<String[]>() {
				public int compare(String[] a, String[] b) {
					return calculateScore(a[1]).compareTo(calculateScore(b[1]));
				}
			});

			for (String[] data : lst) {
				io.println(data[0]);
				io.println(calculateScore(data[1]));
			}
			io.println("==============================");
		}
		io.flush();
	}
}