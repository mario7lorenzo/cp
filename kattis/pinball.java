import java.util.*;

class Point implements Comparable<Point> {
    public int x;
    public int y;
    public int line_id;
    public boolean is_left;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Point another) {
        return this.x - another.x != 0 ? this.x - another.x : (another.is_left ? 1 : 0) - (this.is_left ? 1 : 0) != 0 ? 
        (another.is_left ? 1 : 0) - (this.is_left ? 1 : 0) : (this.is_left ? (this.y - another.y) : (another.y - this.y));
    }

    @Override
    public String toString() {
        return "Point: (" + x + ", " + y + "), Line Id: " + line_id;
    }
}

class Line implements Comparable<Line> {
    public static int pivot;
    public Point left;
    public Point right;
    public int id;

    public Line(Point a, Point b, int id) {
        if (a.x < b.x) {
            this.left = a;
            a.is_left = true;
            this.right = b;
            b.is_left = false;
        } else {
            this.left = b;
            b.is_left = true;
            this.right = a;
            a.is_left = false;
        }

        a.line_id = id;
        b.line_id = id;
        this.id = id;
    }

    public boolean isInRange(int x) {
        return left.x <= x && x <= right.x;
    }

    public Point lowerPoint() {
        return left.y < right.y ? left : right;
    }

    public int maxY() {
        return Math.max(left.y, right.y);
    }

    public double getYatX(int x) {
        if (!isInRange(x)) {
            return 1000005;
        }
        double res = (double)(this.left.y) + ((double)(Math.abs(x - this.left.x)) / (double)(this.right.x - this.left.x)) * (double)(this.right.y - this.left.y);
        return res;
    }

    @Override
    public int compareTo(Line another) {
        if (this.id == another.id) {
            return 0;
        }
        
        double our_y = this.getYatX(Line.pivot);
        double another_y = another.getYatX(Line.pivot);
        
        // System.out.println("ini piv " + Line.pivot);
        // System.out.println("ini our y " + our_y + " " + this.id);
        // System.out.println("ini another y " + another_y + " " + another.id);
        if (our_y - another_y < 0.0) {
            return -1;
        } else {
            return 1;
        }
    }

    @Override
    public String toString() {
        return "Line: Id: " + id + ", Point A: " + left + ", Point B: " + right;
    }
}

class Main {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);
        int n = io.getInt();
        ArrayList<Line> lines = new ArrayList<>();
        TreeSet<Line> active_segments = new TreeSet<>();
        ArrayList<Point> points = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int x1 = io.getInt();
            int y1 = io.getInt();
            int x2 = io.getInt();
            int y2 = io.getInt();

            Point a = new Point(x1, y1);
            Point b = new Point(x2, y2);
            Line l = new Line(a, b, i);
            lines.add(l);
            points.add(a);
            points.add(b);
        }
        final int ball_x = io.getInt(); 
        Collections.sort(points);

        Comparator<Line> comp = new Comparator<Line>() {
            @Override
            public int compare(Line a, Line b) {
                double a_y = a.getYatX(ball_x);
                double b_y = b.getYatX(ball_x);
                // System.out.println("ini our y " + our_y + " " + this);
                // System.out.println("ini another y " + another_y + " " + another);
                if (a_y - b_y < 0.0) {
                    return 1;
                } else {
                    return -1;
                }

            }
        };
        PriorityQueue<Line> pq = new PriorityQueue<>(comp);
        for (Line l : lines) {
            pq.add(l);
        }
        
        // Do the sweep-line processing
        // From the line sweeping processing, we can get the topological
        // ordering from above to bottom. Just need to traverse through 
        // the topological ordering. One buffer node is used to determine
        // the "highest" position, which is the starting ball

        int[] successors = new int[n];
        int curr_pos = -1;

        for (int i = 0; i < points.size(); i++) {
            if (points.get(i).is_left) {
                Line.pivot = points.get(i).x;
                Line above = active_segments.higher(lines.get(points.get(i).line_id));

                if (above == null) {
                    successors[points.get(i).line_id] = curr_pos;
                    curr_pos = points.get(i).line_id;
                } else {
                    successors[points.get(i).line_id] = successors[above.id];
                    successors[above.id] = points.get(i).line_id;
                }
                
                active_segments.add(lines.get(points.get(i).line_id));
            } else {
                active_segments.remove(lines.get(points.get(i).line_id));
            }
        }

        int curr = ball_x;

        for (int i = 0; i < n; i++) {
            if (lines.get(curr_pos).isInRange(curr)) {
                curr = lines.get(curr_pos).lowerPoint().x;
            }
            curr_pos = successors[curr_pos];
        }

        io.println(curr);
        io.flush();
    }
}