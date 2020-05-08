import java.util.*;

class Main {
	public static HashMap<Integer, Integer> jaaphash = new HashMap<Integer, Integer>();
	public static HashMap<Integer, Integer> janhash = new HashMap<Integer, Integer>();
	public static HashMap<Integer, Integer> thijshash = new HashMap<Integer, Integer>();
	public static int[] jaap = new int[200003];
	public static int[] jan = new int[200003];
	public static int[] thijs = new int[200003];
	public static int[] another_arr = new int[200003];
	public static int n;

	public static long countIntersections(int[] a, HashMap<Integer, Integer> b) {
        int[] another_arr = new int[n];
        return mergeSort(a, b, 0, n - 1);
    }
	public static long mergeSort(int[] a, HashMap<Integer, Integer> b, int lb, int ub) {
		int mid;
		long count_pairs = 0;
		if (ub > lb) {
			mid = (ub + lb) / 2;
			count_pairs += mergeSort(a, b, lb, mid);
			count_pairs += mergeSort(a, b, mid + 1, ub);
			count_pairs += merge(a, b, lb, mid + 1, ub);
		}
		return count_pairs;
	}

    public static long merge(int[] a, HashMap<Integer, Integer> b, int lb, int mid, int ub) { 
        int i = lb, j = mid, k = lb; 
        long count_inv = 0; 
 		
        while ((i <= mid - 1) && (j <= ub)) { 
            if (b.get(a[i]) < b.get(a[j])) { 
            	count_inv += ub - j + 1; 
                another_arr[k++] = a[i++]; 
            } 
            else { 
                another_arr[k++] = a[j++];
            } 
        } 

        while (i <= mid - 1) {
            another_arr[k++] = a[i++]; 
        }
  
        while (j <= ub) {
            another_arr[k++] = a[j++]; 
        }

        for (i = lb; i <= ub; i++) 
            a[i] = another_arr[i]; 
  
        return count_inv; 
    } 
  


	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		// long time = System.nanoTime();

		n = io.getInt();

		for (int i = 0; i < n; i++) {
			int x = io.getInt();
			jaaphash.put(x, i);
			jaap[i] = x;
		}

		for (int i = 0; i < n; i++) {
			int x = io.getInt();
			janhash.put(x, i);
			jan[i] = x;
		}

		for (int i = 0; i < n; i++) {
			int x = io.getInt();
			thijshash.put(x, i);
			thijs[i] = x;
		}

		long jaap_jan_intersection = countIntersections(jaap, janhash);
		long jan_thijs_intersection = countIntersections(jan, thijshash);
		long jaap_thijs_intersection = countIntersections(thijs, jaaphash);
		// io.println("jaap_jan");
		// io.println(jaap_jan_intersection);
		// io.println("jan_thijs");
		// io.println(jan_thijs_intersection);
		// io.println("jaap_thijs");
		// io.println(jaap_thijs_intersection);
		long n_choose_2 = ((long)n * (long)(n - 1)) / (long)2;
		// Inclusion-Exclusion Principle
		long triple_intersect = (jaap_jan_intersection + jan_thijs_intersection + jaap_thijs_intersection - n_choose_2) / (long)2;
		io.println(triple_intersect);
		io.flush();
		// long end = System.nanoTime();
		// io.println(end - time);
		// io.flush();
	}
}