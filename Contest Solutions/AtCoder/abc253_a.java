import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt();
        System.out.println(a <= b && b <= c || c <= b && b <= a ? "Yes" : "No");
    }
}
