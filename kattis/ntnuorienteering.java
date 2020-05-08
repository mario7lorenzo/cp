import java.util.*;

class Lecture implements Comparable<Lecture> {
	public int place;
	public long start;
	public long end;

	public Lecture(int place, long start, long end) {
		this.place = place;
		this.start = start;
		this.end = end;
	}

	@Override
	public int compareTo(Lecture another) {
		return this.start - another.start < 0
		? -1
		: this.start - another.start > 0
		? 1
		: this.end - another.end < 0
		? -1
		: this.end - another.end > 0
		? 1
		: this.place - another.place;
	}

	@Override
	public String toString() {
		return "Place: " + place + " Start: " + start + " End: " + end;
	}
}

class Main {
	public static long[][] apsp = new long[1][1];
	public static int[][] memo = new int[1][1];
	public static ArrayList<Lecture> lectures = new ArrayList<>();
	public static int c = -1; 
	public static int l = -1;

	public static void floydWarshall() {
        for (int k = 0; k < c; k++) {
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < c; j++) {
                    apsp[i][j] = Math.min(apsp[i][j], apsp[i][k] + apsp[k][j]);
                }
            }
        }
    }

    public static int memoize(int curr, int prev) {
    	if (curr == l) {
    		return 0;
    	}

    	if (memo[curr][prev] != -1) {
    		return memo[curr][prev];
    	}

    	if (prev == l || lectures.get(curr).start >= lectures.get(prev).end + apsp[lectures.get(curr).place][lectures.get(prev).place]) {
    		memo[curr][prev] = Math.max(memoize(curr + 1, prev), 1 + memoize(curr + 1, curr));
    		return memo[curr][prev];
    	} else {
    		memo[curr][prev] = memoize(curr + 1, prev);
    		return memo[curr][prev];
    	}
    }

	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		int t = io.getInt();

		while (t-- > 0) {
			c = io.getInt();
			l = io.getInt();
			int routes = ((c - 1) * c) / 2;
			apsp = new long[c][c];
			memo = new int[c][c];

			for (int i = 0; i < c; i++) {
				apsp[i][i] = 0;
			}

			for (int k = 0; k < routes; k++) {
				int i = io.getInt();
				int j = io.getInt();
				long tm = io.getLong();
				apsp[i][j] = tm;
				apsp[j][i] = tm;
			}

			floydWarshall();

			lectures = new ArrayList<>();
			for (int i = 0; i < l; i++) {
				int cl = io.getInt();
				long sl = io.getLong();
				long el = io.getLong();
				lectures.add(new Lecture(cl, sl, el));
			}

			Collections.sort(lectures);
			memo = new int[l + 10][l + 10];
			for (int i = 0; i < l + 10; i++) {
				for (int j = 0; j < l + 10; j++) {
					memo[i][j] = -1;
				}
			}

			io.println(memoize(0, l));
		}

		io.flush();
	}
}