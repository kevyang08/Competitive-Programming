import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int r = scanner.nextInt(), c = scanner.nextInt(), dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1}, ans = 0;
        boolean[][] vis = new boolean[r][c];
        char[][] grid = new char[r][c];
        for (int i = 0; i < r; i++) grid[i] = scanner.next().toCharArray();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!vis[i][j] && grid[i][j] != 'X') {
                    ans++;
                    Queue<Integer> qr = new LinkedList<Integer>(), qc = new LinkedList<Integer>();
                    qr.offer(i);
                    qc.offer(j);
                    while (!qr.isEmpty()) {
                        int cr = qr.poll(), cc = qc.poll();
                        if (vis[cr][cc]) continue;
                        vis[cr][cc] = true;
                        for (int k = 0; k < 4; k++) {
                            if (cr + dr[k] >= 0 && cr + dr[k] < r && cc + dc[k] >= 0 && cc + dc[k] < c && !vis[cr + dr[k]][cc + dc[k]] && grid[cr + dr[k]][cc + dc[k]] != 'X') {
                                qr.offer(cr + dr[k]);
                                qc.offer(cc + dc[k]);
                            }
                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
