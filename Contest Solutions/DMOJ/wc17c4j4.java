import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int r = scanner.nextInt(), c = scanner.nextInt(), dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, rs = -1, cs = -1, mx = 0;
        char[][] grid = new char[r][c];
        
        for (int i = 0; i < r; i++) {
        	grid[i] = scanner.next().toCharArray();
        	for (int j = 0; j < c; j++) {
        		if (grid[i][j] == 'H') {
        			rs = i;
        			cs = j;
        		}
        	}
        }
        
        for (int k = 0; k < 4; k++) {
        	int t = 0;
        	for (int i = rs, j = cs; i > -1 && i < r && j > -1 && j < c; i += dx[k], j += dy[k]) if (grid[i][j] == 'C') t++;
        	mx = Math.max(mx, t);
        }
        
        System.out.println(mx);
    }
}
