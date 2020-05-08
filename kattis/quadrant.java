import java.util.*;

class Quadrant {
	public static void main (String[] args) {
		int x, y;
		Scanner scan = new Scanner(System.in);
		x = scan.nextInt();
		y = scan.nextInt();
		int quad;
		if (x > 0 && y > 0) {
			quad = 1;
		} else if (x < 0 && y > 0) {
			quad = 2;
		} else if (x < 0 && y < 0) {
			quad = 3;
		} else {
			quad = 4;
		}
		System.out.println(quad);
	}
}