import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int lb = 1;
		int ub = 1000;
		String res = "ll";
		while (!res.equals("correct")) {
			int mid = (lb + ub) / 2;
			io.println(mid);
			io.flush();
			res = io.getWord();
			if (res.equals("lower")) {
				ub = mid - 1;
			} else {
				lb = mid + 1;
			}
		}
	}
}