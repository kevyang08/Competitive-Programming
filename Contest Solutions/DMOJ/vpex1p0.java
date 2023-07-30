import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int x = scanner.nextInt(), n = scanner.nextInt();
        
        System.out.println(x/n + " " + x%n);
    }
}
