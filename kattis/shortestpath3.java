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
    public static int[] dist = new int[1005];
    public static ArrayList<Pair>[] al = new ArrayList[1005];
    public static boolean[] negative_cycle = new boolean[1005];
    public static int inf = 1000000000;

    public static void bellman_ford(int x, int num_of_nodes) {
        dist[x] = 0;

        for (int i = 0; i < num_of_nodes - 1; i++) {
            for (int j = 0; j < num_of_nodes; j++) {
                if (dist[j] != inf) {
                    for (Pair p : al[j]) {
                        int vtx = p.first;
                        int weight = p.second;
                        if (dist[j] + weight < dist[vtx]) {
                            dist[vtx] = dist[j] + weight;
                        }
                    }    
                }
            }
        }

        // negative cycle checking
        boolean checking = true;
        while (checking) {
            checking = false;
            for (int j = 0; j < num_of_nodes; j++) {
                if (dist[j] != inf) {
                   for (Pair p : al[j]) {
                        int vtx = p.first;
                        int weight = p.second;
                        if (dist[j] != inf && dist[j] + weight < dist[vtx] && !negative_cycle[vtx]) {
                            dist[vtx] = -inf;
                            negative_cycle[vtx] = true;
                            checking = true;
                        }   
                    } 
                } 
            }    
        }
        
    }

    public static void reset() {
        for (int i = 0; i < 1005; i++) {
            dist[i] = inf; 
            negative_cycle[i] = false;
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

            bellman_ford(s, n);

            for (int i = 0; i < q; i++) {
                int node = io.getInt();
                if (dist[node] == inf) {
                    io.println("Impossible");
                } else if (negative_cycle[node]) {
                    io.println("-Infinity");
                } else {
                    io.println(dist[node]);
                }
            }
        }

        io.flush();
    }
}