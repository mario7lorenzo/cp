import java.util.*;

class UFDS {
    private ArrayList<Integer> parents;
    private ArrayList<Integer> ranks;
    private ArrayList<Integer> size_of_set;
    private int num_of_set;

    public UFDS(int n) {
        this.parents = new ArrayList<>();
        this.ranks = new ArrayList<>();
        this.size_of_set = new ArrayList<>();
        this.num_of_set = n;

        for (int i = 0; i < n; i++) {
            this.parents.add(i);
            this.ranks.add(0);
            this.size_of_set.add(1);
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

    public boolean isSameSet(int x, int y) { 
        return findSet(x) == findSet(y); 
    }

    public void unionSet(int m, int n) { 
        if (!isSameSet(m, n)) { 
            this.num_of_set--; 
            int x = findSet(m);
            int y = findSet(n);

            if (this.ranks.get(x) > this.ranks.get(y)) { 
                this.parents.set(y, x); 
                this.size_of_set.set(x, this.size_of_set.get(x) + this.size_of_set.get(y)); 
            } else { 
                this.parents.set(x, y); 
                this.size_of_set.set(y, this.size_of_set.get(y) + this.size_of_set.get(x));
                
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
}