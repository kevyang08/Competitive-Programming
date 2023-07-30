import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int x = scanner.nextInt(), y, m, d;
        
        for (int i = 0; i < x; i++) {
            y = scanner.nextInt();
            m = scanner.nextInt();
            d = scanner.nextInt();
            
            System.out.println(y == 1989 ? m == 2 ? d <= 27 ? "Yes" : "No" : m < 2 ? "Yes" : "No" : y < 1989 ? "Yes" : "No");
        }
    }
}
