import java.util.*;
import java.math.*;

class Different {
	public static void main(String[] args) {
		BigInteger a, b;
		Scanner scan = new Scanner(System.in);
		while (scan.hasNextBigInteger()) {
			a = scan.nextBigInteger();
			b = scan.nextBigInteger();
			System.out.println((a.subtract(b)).abs());
		}
	}
}