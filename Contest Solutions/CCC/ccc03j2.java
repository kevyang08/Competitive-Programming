import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt();
        
        while (a != 0) {
            int s1 = (int)Math.floor(Math.sqrt(a));
            while (a%s1 != 0 && s1 > 1) {
                s1--;
            }
            int s2 = a/s1, p = 2 * s1 + 2 * s2;
            System.out.println("Minimum perimeter is " + p + " with dimensions " + s1 + " x " + s2);
            a = scanner.nextInt();
        }
    }
}
