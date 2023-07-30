import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        String[] names = new String[n];
        int[] bids = new int[n];
        
        for (int i = 0; i < n; i++) {
            names[i] = scanner.next();
            bids[i] = scanner.nextInt();
        }
        
        System.out.println(getHighest(names, bids, n));
    }
    public static String getHighest(String[] names, int[] bids, int n) {
        int max = 0;
        String highest = "";
        for (int i = 0; i < n; i++) {
            if (bids[i] > max) {
                max = bids[i];
                highest = names[i];
            }
        }
        return highest;
    }
}
