import java.util.*;

class IntegerLists {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in, System.out);
		int tc = io.getInt();
		for (int i = 0; i < tc; i++) {
			String command = io.getWord();
			int total = io.getInt();
			String lst = io.getWord();
			String sliced = lst.substring(1, lst.length()-1);
			String[] splitted = sliced.split(",");
			int a = 0;
			int b = total;
			boolean unreversed = true;
			int comm_num = command.length();
			boolean ok = true;
			
			for (int j = 0; j < comm_num; j++) {
				if (command.charAt(j) == 'R') {
					unreversed = !unreversed;
				} else {
					if (unreversed) {
						a++;
					} else {
						b--;
					}
					if (a > b) {
						ok = false;
						break;
					}
				}
			}

			if (!ok) {
				io.println("error");
			} else {
				io.print('[');
				if (unreversed) {
					while (a < b) {
						io.print(splitted[a]);
						a++;
						if (a != b) {
							io.print(',');
						}
					}
				} else {
					while (b > a) {
						io.print(splitted[b-1]);
						b--;
						if (b != a) {
							io.print(',');
						}
					}
				}
				io.println(']');
			}
		}
		io.flush();
	}
}