import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), a = scanner.nextInt(), b = scanner.nextInt();
        System.out.println(Math.abs(n - a * a) < Math.abs(n - b * b) ? 1 : 2);
    }
}
