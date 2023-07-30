import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt();
        System.out.println(2 * n);
        if (n%4 > 0) System.out.print(n%4);
        for (int i = 0; i < n/4; i++) System.out.print(4);
        System.out.println();
    }
}
