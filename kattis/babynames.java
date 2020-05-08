import java.util.*;

class Main {
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		AVLTree<String> all = new AVLTree<>();
		AVLTree<String> male = new AVLTree<>();
		AVLTree<String> female = new AVLTree<>();

		while (true) {
			int command = io.getInt();

			if (command == 0) {
				 break;
			} else if (command == 1) {
				String name = io.getWord();
				int gender = io.getInt();

				all.insert(name);
				if (gender == 1) {
					male.insert(name);
				} else {
					female.insert(name);
				}
			} else if (command == 2) {
				String name = io.getWord();
				all.remove(name);

				if (male.contains(name)) {
					male.remove(name);
				}

				if (female.contains(name)) {
					female.remove(name);
				}
			} else {
				String start = io.getWord();
				String end = io.getWord();
				int type = io.getInt();
				
				if (type == 0) {
					int num = av
				}
			}
		}
	}
}