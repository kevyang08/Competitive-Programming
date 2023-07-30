import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int f = scanner.nextInt(), m = scanner.nextInt(), b = scanner.nextInt(), tf = scanner.nextInt(), tm = scanner.nextInt(), tb = scanner.nextInt();
        System.out.println((tf + tm + tb) + " " + (tf * f + tm * m + tb * b));
    }
}
