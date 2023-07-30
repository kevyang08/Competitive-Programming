import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), c = 0, odd = 0, even = 0;
        
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (a%2 == 1) {
                odd += a;
                if (odd%2 == 0) {
                    c++;
                    odd = 0;
                }
            }
            else {
                even += a;
                if (even != a) {
                    c++;
                    even = 0;
                }
            }
        }
        
        System.out.println(c);
    }
}
