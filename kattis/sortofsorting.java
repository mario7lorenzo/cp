import java.util.*;

class SortOfSorting {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n;
		boolean isfirst = true;
		while (scan.hasNextInt()) {
			n = scan.nextInt();
			if (n == 0) {
				break;
			}
			if (isfirst) {
				isfirst = false;
			} else {
				System.out.print('\n');
			}
			ArrayList<String> lst = new ArrayList<String>();
			for (int i = 0; i < n; i++) {
				String x = scan.next();
				lst.add(x);
			}
			Collections.sort(lst, new Comparator<String>() {
				public int compare(String a, String b) {
					if (a.charAt(0) - b.charAt(0) == 0) {
						return a.charAt(1) - b.charAt(1);
					}
					return a.charAt(0) - b.charAt(0);
				}
			});
			for (int i = 0; i < n; i++) {
				System.out.println(lst.get(i));
			}
		}
	}
}