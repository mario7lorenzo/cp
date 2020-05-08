import java.util.*;

class TreasureHunt {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int r, c;
        r = scan.nextInt();
        c = scan.nextInt();
        char[][] grid = new char[r][c];
        for (int i = 0; i < r; i++) {
            String rows = scan.next();
            for (int j = 0; j < c; j++) {
                char x;
                grid[i][j] = rows.charAt(j);
            }
        }
        int curr_r = 0;
        int curr_c = 0;
        int counter = 0;
        while (true) {
            if (curr_r < 0 || curr_c < 0 || curr_r >= r || curr_c >= c) {
                System.out.println("Out");
                break;
            } else if (grid[curr_r][curr_c] == 'X') {
                System.out.println("Lost");
                break;
            }
            if (grid[curr_r][curr_c] == 'W') {
            	grid[curr_r][curr_c] = 'X';
                curr_c--;
            } else if (grid[curr_r][curr_c] == 'E') {
            	grid[curr_r][curr_c] = 'X';
                curr_c++;
            } else if (grid[curr_r][curr_c] == 'N') {
            	grid[curr_r][curr_c] = 'X';
                curr_r--;
            } else if (grid[curr_r][curr_c] == 'S') {
            	grid[curr_r][curr_c] = 'X';
                curr_r++;
            } else {
                System.out.println(counter);
                break;
            }
            counter++;
        }
    }
}