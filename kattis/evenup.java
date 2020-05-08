import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		Stack<Integer> stk = new Stack<>();
		ArrayList<Integer> lst = new ArrayList<>();
		int n = io.getInt();

		for (int i = 0; i < n; i++) {
			lst.add(io.getInt());
		}

		stk.push(lst.get(0));
		for (int i = 1; i < n; i++) {
			if (stk.isEmpty()) {
				stk.push(lst.get(i));
			} else {
				int x = stk.peek();
				if ((x + lst.get(i))%2 == 0) {
					stk.pop();
				} else {
					stk.push(lst.get(i));
				}
			}		
		}

		io.println(stk.size());
		io.flush();
	}
}