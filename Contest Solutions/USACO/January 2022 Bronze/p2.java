import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        for (; t > 0; t--) {
            int[] a = new int[4], b = new int[4];
            boolean yes = false;
            for (int i = 0; i < 4; i++) a[i] = scanner.nextInt();
            for (int i = 0; i < 4; i++) b[i] = scanner.nextInt();
            if (win(a, b)) {
                for (int i = 1; i <= 10; i++) {
                    for (int j = i; j <= 10; j++) {
                        for (int k = i; k <= 10; k++) {
                            for (int l = i; l <= 10; l++) {
                                int[] temp = {i, j, k, l};
                                if (win(b, temp) && win(temp, a)) {
                                    yes = true;
                                } 
                            }
                        }
                    }
                }
            }
            else {
                for (int i = 1; i <= 10; i++) {
                    for (int j = i; j <= 10; j++) {
                        for (int k = i; k <= 10; k++) {
                            for (int l = i; l <= 10; l++) {
                                int[] temp = {i, j, k, l};
                                if (win(a, temp) && win(temp, b)) {
                                    yes = true;
                                } 
                            }
                        }
                    }
                }
            }
            if (yes) System.out.println("yes");
            else System.out.println("no");
        }
    }
    public static boolean win(int[] a, int[] b) {
        int sa = 0, sb = 0;
        for (int i : a) {
            for (int j : b) {
                if (i > j) sa++;
                else if (j > i) sb++;
            }
        }
        return sa > sb;
    }
}
