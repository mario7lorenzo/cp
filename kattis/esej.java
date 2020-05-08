import java.util.*;

class Main {
	public static StringBuilder start = new StringBuilder("a");

	public static void inc() {
		if (start.length() == 15 && start.equals("zzzzzzzzzzzzzzz")) {
			start = new StringBuilder("a");
		} else {
			boolean done = false;
			for (int i = start.length() - 1; i >= 0; i--) {
				if (start.charAt(i) != 'z') {
					start.setCharAt(i, (char)(start.charAt(i)+1));
					done = true;
				}
				for (int j = i+1; j < start.length(); j++) {
					start.setCharAt(j, 'a');
				}
				if (done) {
					break;
				}
			}		
			if (!done) {
				int lng = start.length() + 1;
				start = new StringBuilder("");
				for (int i = 0; i < lng; i++) {
					start.append("a");
				}
			} 
		}
	}
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int mini = io.getInt();
		int maxi = io.getInt();

		int avg = ((mini + maxi) / 2) + ((mini + maxi) % 2);

		for (int i = 0; i < avg; i++) {
			if (i == 0) {
				io.print(start.toString());
			}
			else {
				io.print(' ');
				io.print(start.toString());
			}
			inc();
		}
		io.println();
		io.flush();
	}
}