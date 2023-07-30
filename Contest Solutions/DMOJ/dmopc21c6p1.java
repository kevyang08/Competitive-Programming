import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int d = scanner.nextInt();
        String x = scanner.next();
        boolean b = false;
        
        int i = 0;
        for (; i < d - 1; i++) {
            if (x.charAt(i) >= x.charAt(i + 1)) {
                System.out.print(x.charAt(i));
            }
            else {
                b = true;
                break;
            }
        }
        if (b) {
            System.out.print(x.charAt(i + 1));
            System.out.print(x.charAt(i));
            i += 2;
        }
        for (; i < d; i++) {
            System.out.print(x.charAt(i));
        }
        System.out.println();
    }
}
