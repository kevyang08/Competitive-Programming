import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), k = scanner.nextInt(), c = 0;
        String s = scanner.next();
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'F' && k == 0) c++;
            if (s.charAt(i) == 'U') {
                if (k > 0) k--;
                if (k == 0) c++;
            }
            else if (s.charAt(i) == 'D') {
                k++;
            }
        }        
        
        System.out.println(c);
    }
}
