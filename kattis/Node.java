import java.util.*;

class Node<T extends Comparable<T>> implements Comparable<Node<T>> {
	private T value;

	public Node(T value) {
		this.value = value;
	}

	public T getValue() {
		return this.value;
	}

	@Override
	public String toString() {
		return this.value.toString();
	}

	@Override
	public int compareTo(Node<T> another) {
		return this.value.compareTo(another.value);
	}
}