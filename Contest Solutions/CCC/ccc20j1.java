import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int s = scanner.nextInt(), m = scanner.nextInt(), l = scanner.nextInt();
        
        System.out.println(s + 2 * m + 3 * l >= 10 ? "happy" : "sad");
    }
}
