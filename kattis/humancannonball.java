import java.util.*;

class Pair {
    public double x;
    public double y;

    public Pair(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

class Main {
    public static ArrayList<Pair> lst = new ArrayList<>();
    public static double[][] am = new double[1][1];
    public static double[] min_time = new double[1];
    public static double inf = 1000000000.0;

    public static void dijkstra(int x) {
        for (int i = 0; i < lst.size(); i++) {
            min_time[i] = inf;
        }
        PriorityQueue<Integer> q = new PriorityQueue<>();
        min_time[x] = 0;
        q.add(x);

        while (!q.isEmpty()) {
            int curr = q.peek();
            q.remove();

            for (int i = 0; i < lst.size(); i++) {
                if (i != x && min_time[i] > min_time[curr] + am[curr][i]) {
                    min_time[i] = min_time[curr] + am[curr][i];
                    q.add(i);
                }
            }
        }
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);

        double start_x = io.getDouble();
        double start_y = io.getDouble();
        double end_x = io.getDouble();
        double end_y = io.getDouble();

        lst.add(new Pair(start_x, start_y));
        lst.add(new Pair(end_x, end_y));

        int n = io.getInt();
        for (int i = 0; i < n; i++) {
            lst.add(new Pair(io.getDouble(), io.getDouble()));
        }

        am = new double[n + 2][n + 2];
        min_time = new double[n + 2];

        double d = Math.hypot(lst.get(0).x - lst.get(1).x, lst.get(0).y - lst.get(1).y);
        am[0][1] = d / 5.0;
        am[1][0] = d / 5.0;
        am[0][0] = 0;
        am[1][1] = 0;

        for (int i = 2; i < n + 2; i++) {
            d = Math.hypot(lst.get(0).x - lst.get(i).x, lst.get(0).y - lst.get(i).y);
            am[0][i] = d / 5.0;
            am[i][0] = (Math.abs(d - 50.0) / 5.0) + 2.0;
        }

        for (int i = 2; i < n + 2; i++) {
            d = Math.hypot(lst.get(1).x - lst.get(i).x, lst.get(1).y - lst.get(i).y);
            am[1][i] = d / 5.0;
            am[i][1] = (Math.abs(d - 50.0) / 5.0) + 2.0;
        }

        for (int i = 2; i < n + 2; i++) {
            for (int j = 2; j < n + 2; j++) {
                d = Math.hypot(lst.get(i).x - lst.get(j).x, lst.get(i).y - lst.get(j).y);
                am[i][j] = (Math.abs(d - 50.0) / 5.0) + 2.0;
            }
        }

        dijkstra(0);
        io.println(min_time[1]);
        io.flush();
    }
}