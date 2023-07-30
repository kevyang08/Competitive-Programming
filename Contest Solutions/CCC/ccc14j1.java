import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt();
        
        if (a + b + c != 180) 
            System.out.println("Error");
        else if (a == 60 && b == 60 && c == 60) 
            System.out.println("Equilateral");
        else if (a == b || b == c || a == c) 
            System.out.println("Isosceles");
        else if (a != b && b != c && a != c) 
            System.out.println("Scalene");
    }
}
