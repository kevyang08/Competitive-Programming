import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int h = scanner.nextInt();
        
        for (int i = 1; i <= h/2; i++) {
            for (int n = 1; n < i * 2; n++) {
                System.out.print("*");
            }
            for (int n = 2 * (2 * i - 1); n < 2 * h; n++) {
                System.out.print(" ");
            }
            for (int n = 1; n < i * 2; n++) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int i = 0; i < 2 * h; i++) {
            System.out.print("*");
        }
        System.out.println();
        for (int i = h/2; i > 0; i--) {
            for (int n = 1; n < i * 2; n++) {
                System.out.print("*");
            }
            for (int n = 2 * (2 * i - 1); n < 2 * h; n++) {
                System.out.print(" ");
            }
            for (int n = 1; n < i * 2; n++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
