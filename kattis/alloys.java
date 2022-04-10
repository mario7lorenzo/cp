import java.util.*;

class Main {
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in);

        double dec = sc.nextDouble();

        if (dec > 1) {
            System.out.println(0.25);
        } else {
            System.out.println(dec*dec/4.0);
        }
    }
}
