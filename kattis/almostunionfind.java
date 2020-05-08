import java.util.*;

class UFDS {
    private ArrayList<Integer> parents;
    private ArrayList<Integer> ranks;
    private ArrayList<Integer> size_of_set;
    private ArrayList<Long> sum_of_set;
    private int num_of_set;

    public UFDS(int n) {
        this.parents = new ArrayList<>();
        this.ranks = new ArrayList<>();
        this.size_of_set = new ArrayList<>();
        this.sum_of_set = new ArrayList<>();
        this.num_of_set = n;

        for (int i = 0; i <= 2*n + 1; i++) {
            this.ranks.add(0);
            this.size_of_set.add(1);
            if (i > n) {
                this.parents.add(i);
                this.sum_of_set.add(((long)i - n - 1));
            } else {
                this.parents.add(n + i + 1);
                this.sum_of_set.add(0L);
            }
        }
    }

    public int findSet(int x) { 
        if (parents.get(x) == x)  {
            return x;
        } else {
            int value = findSet(this.parents.get(x)); 
            parents.set(x, value);
            return value; 
        } 
    }

    public Boolean isSameSet(int x, int y) { 
        return findSet(x) == findSet(y); 
    }

    public void unionSet(int m, int n) { 
        if (!isSameSet(m, n)) { 
            this.num_of_set--; 
            int x = findSet(m);
            int y = findSet(n);

            if (this.ranks.get(x) > this.ranks.get(y)) { 
                this.size_of_set.set(x, this.size_of_set.get(x) + this.size_of_set.get(y)); 
                this.sum_of_set.set(x, this.sum_of_set.get(x) + this.sum_of_set.get(y));
                this.parents.set(y, x);
            } else { 
                this.size_of_set.set(y, this.size_of_set.get(y) + this.size_of_set.get(x));
                this.sum_of_set.set(y, this.sum_of_set.get(x) + this.sum_of_set.get(y));
                this.parents.set(x, y); 
                if (this.ranks.get(x) == this.ranks.get(y)) { 
                    this.ranks.set(y, this.ranks.get(y) + 1); 
                } 
            } 
        }
    }

    public int numOfDisjointSets() { 
        return this.num_of_set; 
    }
    
    public int sizeOfSet(int x) { 
        return this.size_of_set.get(findSet(x)); 
    }

    public void move(int from, int to) {
        if (!isSameSet(from, to)) {
            int x = this.parents.get(from);
            int y = this.parents.get(to);
            this.size_of_set.set(x, this.size_of_set.get(x) - 1);
            this.size_of_set.set(y, this.size_of_set.get(y) + 1);
            this.parents.set(from, y);
            this.sum_of_set.set(x, this.sum_of_set.get(x) - from);
            this.sum_of_set.set(y, this.sum_of_set.get(y) + from);
        }
    }

    public long sumSet(int x) {
        return sum_of_set.get(findSet(x));
    }
}

class Main {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);

        while (io.hasMoreTokens()) {
        	int n = io.getInt();
	        int m = io.getInt();

	        UFDS ufds = new UFDS(n);

	        for (int i = 0; i < m; i++) {
	            int op = io.getInt();
	            if (op == 1) {
	                ufds.unionSet(io.getInt(), io.getInt());
	            } else if (op == 2) {
	                ufds.move(io.getInt(), io.getInt());
	            } else {
	                int x = io.getInt();
	                io.println(ufds.sizeOfSet(x) + " " + ufds.sumSet(x));
	            }
	        }
        }
        
        io.flush();
    }
}