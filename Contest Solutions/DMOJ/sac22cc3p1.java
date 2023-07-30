import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int h = scanner.nextInt(), s = scanner.nextInt(), q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            System.out.println(h -= s);
        }
    }
}
