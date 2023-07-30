import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int l1 = scanner.nextInt(), r1 = scanner.nextInt(), l2 = scanner.nextInt(), r2 = scanner.nextInt(), l = Math.max(l1, l2), r = Math.min(r1, r2);
        System.out.println(Math.max(0, r - l));
    }
}
