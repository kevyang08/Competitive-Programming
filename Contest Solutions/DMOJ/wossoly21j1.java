import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        
        System.out.println(t <= 0 ? "S" : t < 100 ? "L" : "G");
    }
}
