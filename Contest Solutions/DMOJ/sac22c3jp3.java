import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        double p = 1;
        for (int i = 0; i < n; i++) {
            char c = scanner.next().charAt(0);
            if (c == 'B') p *= 0.8;
            else if (c == 'C') p *= 0.6;
            else if (c == 'D') p *= 0.4;
            else if (c == 'E') p *= 0.2;
        }
        System.out.println(p);
    }
}
