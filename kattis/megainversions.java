import java.util.*;

class Pair {
	public int first;
	public int second;

	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	public int getFirst() {
		return this.first;
	}

	public int getSecond() {
		return this.second;
	}

	@Override
	public String toString() {
		return "Pair (" + this.first + ", " + this.second + ")"; 
	}
}

class Main {
	
	public static HashMap<Integer, Long> left_bigger;
	public static HashMap<Integer, Long> right_smaller;

	public static void countInversion(Pair[] arr, int n) {
		Pair[] another_arr = new Pair[n];
		mergeSort(arr, another_arr, 0, n - 1);
	}

	public static void mergeSort(Pair[] arr, Pair[] another_arr, int lb, int ub) {
		int mid;
		if (ub > lb) {
			mid = (ub + lb) / 2;
			mergeSort(arr, another_arr, lb, mid);
			mergeSort(arr, another_arr, mid + 1, ub);
			merge(arr, another_arr, lb, mid + 1, ub);
		}
	}

	public static void merge(Pair[] arr, Pair[] another_arr, int lb, int mid, int ub) {
		int i = lb, j = mid, k = lb;

		while ((i <= mid - 1) && (j <= ub)) {
			if (arr[i].getFirst() > arr[j].getFirst()) {
				left_bigger.put(arr[j].getSecond(), left_bigger.get(arr[j].getSecond()) + (long)(mid - i));
				another_arr[k++] = arr[j++];
			} else {
				another_arr[k++] = arr[i++];
			}
		}

		while (i <= mid - 1) {
			another_arr[k++] = arr[i++];
		}

		while (j <= ub) {
			another_arr[k++] = arr[j++];
		}

		for (i = lb; i <= ub; i++) {
			arr[i] = another_arr[i];
		}
	}

	public static void countReverseInversion(Pair[] arr, int n) {
		Pair[] another_arr = new Pair[n];
		mergeSortReversed(arr, another_arr, 0, n - 1);
	}

	public static void mergeSortReversed(Pair[] arr, Pair[] another_arr, int lb, int ub) {
		int mid;
		if (ub > lb) {
			mid = (ub + lb) / 2;
			mergeSortReversed(arr, another_arr, lb, mid);
			mergeSortReversed(arr, another_arr, mid + 1, ub);
			mergeReversed(arr, another_arr, lb, mid + 1, ub);
		}
	}

	public static void mergeReversed(Pair[] arr, Pair[] another_arr, int lb, int mid, int ub) {
		int i = lb, j = mid, k = lb;

		while ((i <= mid - 1) && (j <= ub)) {
			if (arr[i].getFirst() <= arr[j].getFirst()) {
				another_arr[k++] = arr[j++];
			} else {
				right_smaller.put(arr[i].getSecond(), right_smaller.get(arr[i].getSecond()) + (long)(ub - j + 1));
				another_arr[k++] = arr[i++];
			}
		}

		while (i <= mid - 1) {
			another_arr[k++] = arr[i++];
		}

		while (j <= ub) {
			another_arr[k++] = arr[j++];
		}

		for (i = lb; i <= ub; i++) {
			arr[i] = another_arr[i];
		}
	}


	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int n = io.getInt();

		Pair[] lst1 = new Pair[n];
		Pair[] lst2 = new Pair[n];
		left_bigger = new HashMap<Integer, Long>();
		right_smaller = new HashMap<Integer, Long>();

		for (int i = 0; i < n; i++) {
			int x = io.getInt();
			lst1[i] = new Pair(x, i);
			lst2[i] = new Pair(x, i);
			left_bigger.put(i, 0L);
			right_smaller.put(i, 0L);
		}

		countInversion(lst1, n);
		countReverseInversion(lst2, n);

		long counter = 0;
		for (int i = 0; i < n; i++) {
			counter += (left_bigger.get(i) * right_smaller.get(i));
		}
		io.println(counter);
		io.flush();
	}
}