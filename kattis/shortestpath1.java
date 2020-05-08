import java.util.*;

class Pair implements Comparable<Pair> {
    public int first;
    public int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair another) {
        if (this.second - another.second == 0) {
            return this.first - another.first;
        }
        return this.second - another.second;
    }

    @Override
    public String toString() {
        return first + " " + second;
    }
}

class Main {
    public static int[] dist = new int[10050];
    public static ArrayList<Pair>[] al = new ArrayList[10050];
    public static int inf = 1000000000;

    public static void dijkstra(int x) {
        dist[x] = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(x, dist[x]));

        while(!pq.isEmpty()) {
            Pair coor = pq.peek();
            pq.remove();
            int u = coor.first, w = coor.second;
            if (w > dist[u]) {
                continue;
            }

            for (Pair i : al[u]) {
                int weight = i.second;
                int vtx = i.first;

                if (dist[vtx] > dist[u] + weight) {
                    dist[vtx] = dist[u] + weight;
                    pq.add(new Pair(vtx, dist[vtx]));
                }
            }
            
        }
    }

    public static void reset() {
        for (int i = 0; i < 10050; i++) {
            dist[i] = inf; 
        }
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);

        boolean isfirst = true;
        while(io.hasMoreTokens()) {
            int n = io.getInt();
            int m = io.getInt();
            int q = io.getInt();
            int s = io.getInt();

            if (n == 0 && m == 0 && q == 0 && s == 0) {
                break;
            }

            for (int i = 0; i < n; i++) {
                al[i] = new ArrayList<>();
            }

            for (int i = 0; i < m; i++) {
                int u = io.getInt();
                int v = io.getInt();
                int w = io.getInt();

                al[u].add(new Pair(v, w));
            }

            reset();

            if (isfirst) {
                isfirst = false;
            } else {
                io.println();
            }

            dijkstra(s);

            for (int i = 0; i < q; i++) {
                int node = io.getInt();
                if (dist[node] == inf) {
                    io.println("Impossible");
                } else {
                    io.println(dist[node]);
                }
            }
        }

        io.flush();
    }
}