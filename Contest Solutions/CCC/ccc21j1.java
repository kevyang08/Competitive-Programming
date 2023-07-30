import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int b = scanner.nextInt(), p = 5 * b - 400;
        
        System.out.println(p);
        System.out.println(p == 100 ? 0 : p > 100 ? -1 : 1);
    }
}
