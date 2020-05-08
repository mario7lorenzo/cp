import java.util.*;
import java.math.*;

class Statistics {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int counter = 1;
		while (scan.hasNextInt()) {
			int tot = scan.nextInt();
			int mini = 1000001;
			int maxi = -1000001;
			for (int i = 0; i < tot; i++) {
				int num = scan.nextInt();
				mini = Math.min(num, mini);
				maxi = Math.max(num, maxi);
			}
			System.out.printf("Case %d: %d %d %d%n", counter, mini, maxi, maxi - mini);
			counter++;
		}
	}
}