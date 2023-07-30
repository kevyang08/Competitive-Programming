import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int l = scanner.nextInt(), h = scanner.nextInt(), w = scanner.nextInt(), d = scanner.nextInt();
        
        System.out.println(l * h * w - (h * Math.PI * Math.pow(d/2.0, 2)));
    }
}
