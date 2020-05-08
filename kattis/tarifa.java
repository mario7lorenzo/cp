import java.util.*;

class Tarifa {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int acc, lim, mth;
		lim = scan.nextInt();
		mth = scan.nextInt();
		acc = lim;
		for (int i = 0; i < mth; i++) {
			int am = scan.nextInt();
			acc -= am;
			acc += lim;
		}
		System.out.println(acc);
	}
}