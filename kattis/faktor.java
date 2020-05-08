import java.util.*;

class faktor {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int result;
		if (a == 1) {
			result = a * b;
		} else {
			result = (a * (b - 1)) + 1;
		}
		System.out.println(result);
	}
}