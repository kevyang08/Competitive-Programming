import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt(), d = scanner.nextInt(), s = Math.min(a, Math.min(b, Math.min(c, d))), l = Math.max(a, Math.max(b, Math.max(c, d)));
        
        System.out.println(s);
        System.out.println(l);
    }
}
