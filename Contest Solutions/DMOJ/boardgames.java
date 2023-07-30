import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), m = scanner.nextInt();
        boolean[] vis = new boolean[10000001];
        Queue<Integer> q = new LinkedList<Integer>(), c = new LinkedList<Integer>();
        q.offer(n);
        c.offer(0);
        while (!q.isEmpty()) {
            int cur = q.poll(), t = c.poll();
            if (vis[cur]) continue;
            if (cur == m) {
                System.out.println(t);
                break;
            }
            if (cur * 3 <= 10000000 && !vis[cur * 3]) {
                q.offer(cur * 3);
                c.offer(t + 1);
            }
            if (cur - 1 > 0 && !vis[cur - 1]) {
                q.offer(cur - 1);
                c.offer(t + 1);
            }
            if (cur - 3 > 0 && !vis[cur - 3]) {
                q.offer(cur - 3);
                c.offer(t + 1);
            }
            if (cur%2 == 0 && cur/2 > 0 && !vis[cur/2]) {
                q.offer(cur/2);
                c.offer(t + 1);
            }
            vis[cur] = true;
        }
    }
}
