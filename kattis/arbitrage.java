import java.util.*;

class Main {
    public static HashMap<String, Integer> curr_to_id = new HashMap<>();
    public static double[][] apsp = new double[1][1];
    public static int c = -1;
    public static int r = -1;

    public static void floydWarshall() {
        for(int k=0; k < c; k++)
            for(int i = 0; i < c; i++)
                for(int j = 0; j < c; j++)
                    apsp[i][j] = Math.max(apsp[i][j], apsp[i][k] + apsp[k][j]);
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);
        
        while (true) {
            c = io.getInt();
            if (c == 0) {
                break;
            }
            curr_to_id = new HashMap<>();
            apsp = new double[c][c];

            for (int i = 0; i < c; i++) {
                for (int j = 0; j < c; j++) {
                    apsp[i][j] = -1E9;
                }
            }

            for (int i = 0; i < c; i++) {
                String curr = io.getWord();
                curr_to_id.put(curr, i);
                apsp[i][i] = 0.0;
            }


            r = io.getInt();
            for (int i = 0; i < r; i++) {
                String curr1 = io.getWord();
                String curr2 = io.getWord();
                String[] ratio = io.getWord().split(":");
                apsp[curr_to_id.get(curr1)][curr_to_id.get(curr2)] = Math.log((Double.parseDouble(ratio[1]) / Double.parseDouble(ratio[0])));
            }

            floydWarshall();
            boolean is_arbitrage = false;
            for (int i = 0; i < c; i++) {
                if (apsp[i][i] > 0.0) {
                    is_arbitrage = true;
                }
            }

            if (!is_arbitrage) {
                io.println("Ok");
            } else {
                io.println("Arbitrage");
            }
        }

        io.flush();
    }
}