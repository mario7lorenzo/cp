import java.util.*;
import java.math.*;

class GuessingGame {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while (scan.hasNextLine()) {
			int lb = 0;
			int ub = 11;
			boolean isfirst = true;
			String num_st = scan.nextLine();
			int num = Integer.parseInt(num_st);
			if (num == 0) {
				break;
			}
			while (true) {
				if (isfirst) {
					isfirst = false;
				} else {
					num_st = scan.nextLine();
					num = Integer.parseInt(num_st);
				}
				String status = scan.nextLine();
				// System.out.println(lb);
				// System.out.println(ub);
				if (status.equals("too high")) {
					ub = Math.min(ub, num);
				} else if (status.equals("too low")) {
					lb = Math.max(lb, num);
				} else {
					if (lb < num && ub > num) {
						System.out.println("Stan may be honest");
					} else {
						System.out.println("Stan is dishonest");
					}
					break;
				}
			}
		}
	}
}