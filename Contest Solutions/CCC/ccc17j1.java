import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int x = scanner.nextInt(), y = scanner.nextInt();
        
        System.out.println(x > 0 ? y > 0 ? 1 : 4 : y > 0 ? 2 : 3);
    }
}
