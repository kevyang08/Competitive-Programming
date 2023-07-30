import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), x;
        String s;
        
        for (int i = 0; i < n; i++) {
            x = scanner.nextInt();
            s = scanner.nextLine();
            System.out.println((i + 1) + s.substring(0, x) + (s.substring(x + 1)));
        }
    }
}
