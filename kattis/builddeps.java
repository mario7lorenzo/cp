import java.util.*;

class Main {
	public static HashMap<String, ArrayList<String>> hmap = new HashMap<>();
	public static HashMap<String, Boolean> visited = new HashMap<>();
	public static Stack<String> stk = new Stack<>();

	public static void dfs(String x) {
		visited.put(x, true);
		for (String neighbor : hmap.get(x)) {
			if (!visited.get(neighbor)) {
				dfs(neighbor);
			}
		}
		stk.add(x);
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = Integer.parseInt(scan.nextLine());
		

		for (int k = 0; k < n; k++) {
			String[] splitted = scan.nextLine().split(" ");
			String file = splitted[0].substring(0, splitted[0].length() - 1);
			if (!hmap.containsKey(file)) {
				hmap.put(file, new ArrayList<>());
			}
			visited.put(file, false);

			for (int i = 1; i < splitted.length; i++) {
				if (!hmap.containsKey(splitted[i])) {
					ArrayList<String> al = new ArrayList<>();
					al.add(file);
					hmap.put(splitted[i], al);
				} else {
					hmap.get(splitted[i]).add(file);
				}
			}
		}

		String changed = scan.nextLine();

		dfs(changed);
		while(!stk.isEmpty()) {
			System.out.println(stk.peek());
			stk.pop();
		}
	}
}