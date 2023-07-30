import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        
        for (; t > 0; t--) {
            int n = scanner.nextInt();
            long[] h = new long[n];
            for (int i = 0; i < n; i++) h[i] = scanner.nextLong();
            if (n == 1) System.out.println(0);
            else if (n == 2) System.out.println(h[0] == h[1] ? 0 : -1);
            else {
                long c = 0;
                boolean thing = true;
                if (h[0] > h[1] || h[n - 1] > h[n - 2]) thing = false;
                for (int i = 1; i < n - 1; i++) {
                    if (h[i] > h[i - 1]) {
                        long d = h[i] - h[i - 1];
                        c += 2 * d;
                        h[i] -= d;
                        h[i + 1] -= d;
                    }
                    if (h[i] > h[i + 1]) {
                        long d = h[i] - h[i + 1];
                        c += 2 * d;
                        h[i] -= d;
                        h[i - 1] -= d;
                    }
                    if (h[i] < 0 || h[i - 1] < 0 || h[i + 1] < 0) thing = false;
                }
                if (h[0] > h[1] || h[n - 1] > h[n - 2]) thing = false;
                for (int i = n - 2; i > 0; i--) {
                    if (h[i] > h[i - 1]) {
                        long d = h[i] - h[i - 1];
                        c += 2 * d;
                        h[i] -= d;
                        h[i + 1] -= d;
                    }
                    if (h[i] > h[i + 1]) {
                        long d = h[i] - h[i + 1];
                        c += 2 * d;
                        h[i] -= d;
                        h[i - 1] -= d;
                    }
                    if (h[i] < 0 || h[i - 1] < 0 || h[i + 1] < 0) thing = false;
                }
                if (h[0] > h[1] || h[n - 1] > h[n - 2]) thing = false;
                if (thing) System.out.println(c);
                else System.out.println(-1);
            }
        }
    }
}
