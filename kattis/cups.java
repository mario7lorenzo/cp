import java.util.*;
import java.lang.*;


class Main {
	public static boolean is_number(String x) {
		try {
			int n = Integer.parseInt(x);
		} catch (NumberFormatException e) {
			return false;
		}
		return true;
	}
	public static void main(String[] args) {
		int n;
		Kattio io = new Kattio(System.in);
		n = io.getInt();
		List<int[]> lst = new ArrayList<int[]>();
		List<String> colors = new ArrayList<String>();
		TreeMap<Double, String> treemap = new TreeMap<Double, String>(); 
		for (int i = 0; i < n; i++) {
			String a, b, color;
			a = io.getWord();
			b = io.getWord();
			double r;
			if (is_number(a)) {
				r = (double)(Integer.parseInt(a)) / 2.0;
				color = b;
			} else {
				r = Integer.parseInt(b);
				color = a;
			}
			treemap.put(r, color);
		}
		Set<Map.Entry<Double, String>> set =  treemap.entrySet();
		for (Map.Entry<Double, String> me : set) {
			io.println(me.getValue());
		}
		io.flush();
	}
}