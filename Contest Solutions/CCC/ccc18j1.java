import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int d1 = scanner.nextInt(), d2 = scanner.nextInt(), d3 = scanner.nextInt(), d4 = scanner.nextInt();
        
        System.out.println((d1 == 8 || d1 == 9) && (d4 == 8 || d4 == 9) && d2 == d3 ? "ignore" : "answer");
    }
}
