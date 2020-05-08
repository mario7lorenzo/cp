import java.util.*;

class Autori {
	public static void main(String[] args) {
		String st;
		Scanner scan = new Scanner(System.in);
		st = scan.nextLine();
		String[] splitted = st.split("-");
		for (String a : splitted) {
			System.out.print(a.charAt(0));
		}
		System.out.print('\n');
	}
}