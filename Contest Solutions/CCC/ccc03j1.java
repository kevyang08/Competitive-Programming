import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt(), s = scanner.nextInt(), h = scanner.nextInt();
        
        for (int i = 0; i < t ; i++) {
            System.out.print("*");
            for (int n = 0; n < s; n++) {
                System.out.print(" ");
            }
            System.out.print("*");
            for (int n = 0; n < s; n++) {
                System.out.print(" ");
            }
            System.out.println("*");
        }
        for (int i = 0; i < 2 * s + 3; i++) {
            System.out.print("*");
        }
        System.out.println();
        for (int i = 0; i < h; i++) {
            for(int n = 0; n < s + 1; n++) {
                System.out.print(" ");
            }
            System.out.println("*");
        }
    }
}
