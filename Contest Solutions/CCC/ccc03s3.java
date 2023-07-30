import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), r = scanner.nextInt(), c = scanner.nextInt(), dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1}, ans = 0;
        ArrayList<Integer> ar = new ArrayList<Integer>();
        boolean[][] vis = new boolean[r][c];
        char[][] grid = new char[r][c];
        for (int i = 0; i < r; i++) grid[i] = scanner.next().toCharArray();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!vis[i][j] && grid[i][j] != 'I') {
                    int a = 0;
                    Queue<Integer> qr = new LinkedList<Integer>(), qc = new LinkedList<Integer>();
                    qr.offer(i);
                    qc.offer(j);
                    while (!qr.isEmpty()) {
                        int cr = qr.poll(), cc = qc.poll();
                        if (vis[cr][cc]) continue;
                        a++;
                        vis[cr][cc] = true;
                        for (int k = 0; k < 4; k++) {
                            if (cr + dr[k] >= 0 && cr + dr[k] < r && cc + dc[k] >= 0 && cc + dc[k] < c && !vis[cr + dr[k]][cc + dc[k]] && grid[cr + dr[k]][cc + dc[k]] != 'I') {
                                qr.offer(cr + dr[k]);
                                qc.offer(cc + dc[k]);
                            }
                        }
                    }
                    ar.add(a);
                }
            }
        }
        Collections.sort(ar);
        for (int i = ar.size() - 1; i >= 0; i--) {
            if (n - ar.get(i) < 0) break;
            ans++;
            n -= ar.get(i);
        }
        System.out.printf("%d room%s, %d square metre(s) left over", ans, ans == 1 ? "" : "s", n);
    }
}
