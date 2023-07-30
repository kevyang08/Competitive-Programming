import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), f[] = new int[n + 1], a[] = new int[n + 1];
        boolean[] vis = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<Integer>(), t = new LinkedList<Integer>();
        f[1] = 1;
        a[1] = 2;
        for (int i = 2; i <= n; i++) {
            f[i] = (f[i - 1] + f[i - 2])%2021;
            a[i] = f[i] + i%50;
        }
        q.offer(1);
        t.offer(0);
        while (!q.isEmpty()) {
            int cur = q.poll(), ct = t.poll();
            if (vis[cur]) continue;
            vis[cur] = true;
            if (cur == n) {
                System.out.println(ct);
                break;
            }
            if (cur - 1 > 0 && !vis[cur - 1]) {
                q.add(cur - 1);
                t.add(ct + 1);
            }
            if (cur + 1 <= n && !vis[cur + 1]) {
                q.add(cur + 1);
                t.add(ct + 1);
            }
            if (cur - a[cur] > 0 && !vis[cur - a[cur]]) {
                q.add(cur - a[cur]);
                t.add(ct + 1);
            }
            if (cur + a[cur] <= n && !vis[cur + a[cur]]) {
                q.add(cur + a[cur]);
                t.add(ct + 1);
            }
        }
    }
}
