import java.util.*;

class APrizeNoOneCanWin {
	public static void main(String[]args) {
		Scanner scan = new Scanner(System.in);
		int n, x;
		int counter = 0;
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		n = scan.nextInt();
		x = scan.nextInt();
		for (int i = 0; i < n; i++) {
			pq.add(scan.nextInt());
		}
		int currmax = 0;
		while (!pq.isEmpty()) {
			int num = pq.remove();
			if (counter == 0) {
				counter++;
			}
			else {
				if (currmax + num > x) {
					break;
				}
				counter++;
			}
			currmax = num;
		}
		System.out.println(counter);
	}
}