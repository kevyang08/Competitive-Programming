import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        if (n != 1 && n != 4) {
            System.out.println(" * * *");
        }
        else {
            System.out.println();
        }
        
        if (n == 0 || n == 4 || n == 8 || n == 9) {
            for (int i = 0; i < 3; i++) {
                System.out.println("*     *");
            }
        }
        else if (n == 5 || n == 6) {
            for (int i = 0; i < 3; i++) {
                System.out.println("*");
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                System.out.println("      *");
            }
        }
        
        if (n != 0 && n != 1 && n != 7) {
            System.out.println(" * * *");
        }
        else {
            System.out.println();
        }
        
        if (n == 2) {
            for (int i = 0; i < 3; i++) {
                System.out.println("*");
            }
        }
        else if (n == 0 || n == 6 || n == 8) {
            for (int i = 0; i < 3; i++) {
                System.out.println("*     *");
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                System.out.println("      *");
            }
        }
        
        if (n != 1 && n != 4 && n != 7) {
            System.out.println(" * * *");
        }
        else {
            System.out.println();
        }
    }
}
