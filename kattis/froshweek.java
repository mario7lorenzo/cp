import java.util.List;
import java.util.ArrayList;
import java.util.Vector;
import java.util.Collections;

class Main {
    public static long countInversion(int arr[], int size) {
        int[] another_arr = new int[size];
        return mergeSort(arr, another_arr, 0, size - 1);
    }

    public static long mergeSort(int arr[], int another_arr[], int lb, int ub) {
        int mid;
        long count_inv = 0; 
        if (ub > lb) { 
            mid = (lb + ub) / 2; 
            count_inv = mergeSort(arr, another_arr, lb, mid); 
            count_inv += mergeSort(arr, another_arr, mid + 1, ub);
            count_inv += merge(arr, another_arr, lb, mid + 1, ub);
        }
        return count_inv;
    }   

    public static long merge(int arr[], int another_arr[], int lb, int mid, int ub) { 
        int i = lb, j = mid, k = lb; 
        long count_inv = 0; 
 
        while ((i <= mid - 1) && (j <= ub)) { 
            if (arr[i] <= arr[j]) { 
                another_arr[k++] = arr[i++]; 
            } 
            else { 
                another_arr[k++] = arr[j++]; 
                count_inv += (mid - i); 
            } 
        } 

        while (i <= mid - 1) {
            another_arr[k++] = arr[i++]; 
        }
  
        while (j <= ub) {
            another_arr[k++] = arr[j++]; 
        }

        for (i = lb; i <= ub; i++) 
            arr[i] = another_arr[i]; 
  
        return count_inv; 
    } 
  

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);
        int n = io.getInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = io.getInt();
        }
        io.println(countInversion(arr, n));
        io.flush();
    }
}