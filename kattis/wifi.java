import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

class Main {
    static int n, m;

    public static double half_rounding(double x) {
        double twice_x = x * 2;
        return twice_x == Math.floor(twice_x) ? x : x - 0.25;
    }

    public static int count_wifi(List<Integer> arr, double pt) {
    	int i = 0;
    	int wifi = 0;
    	while (i < m) {
            double wifi_point = arr.get(i) + pt;
            wifi++;

            while (i < m) {
                if (arr.get(i) <= wifi_point + pt) {
                    i++;
                } else {
                    break;
                }
            }
        }
        return wifi;
    }

    public static double binary_search(List<Integer> arr, double lb, double ub) {
        double mid = half_rounding((lb + ub) / 2);

    	if ((ub - lb) <= 0.5) {
    		return ub;
    	}

        int mid_count = count_wifi(arr, mid);

        if (mid_count <= n) {
            return binary_search(arr, lb, mid);
        } else {
            return binary_search(arr, mid, ub);
        }
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);
        int tc = io.getInt();
        for (int k = 0; k < tc; k++) {

            n = io.getInt();
            m = io.getInt();

            List<Integer> arr = new ArrayList<Integer>();
            for (int i = 0; i < m; i++) {
                arr.add(io.getInt());
            }

            if (n >= m) {
                io.println(0.0);
            } else {
                Collections.sort(arr);
            
                double max_dist = (double)(arr.get(m - 1) - arr.get(0)) / 2.0; 
                io.println(binary_search(arr, 0.0, max_dist));
            }
        }
        io.flush();
    }
}