import java.util.*;

class JudgingMoose {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int l, r;
		l = scan.nextInt();
		r = scan.nextInt();
		if (l == 0 && r == 0) {
			System.out.print("Not a moose");
		}
		else {
			if (l == r) {
				System.out.print("Even ");
			} else {
				System.out.print("Odd ");
			}
			System.out.println(Math.max(l, r) * 2);
		}
	}
}