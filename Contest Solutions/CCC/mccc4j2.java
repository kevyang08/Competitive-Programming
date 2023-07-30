import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), a = scanner.nextInt(), b = scanner.nextInt(), s1 = 0, s2 = 0;
        
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt(), y = scanner.nextInt();
            s1 += a > x ? 1 : 2;
            s2 += b > y ? 1 : 2;
        }
        
        System.out.println(s1 == s2 ? "Tie!" : s1 < s2 ? "Andrew wins!" : "Tommy wins!");
    }
}
