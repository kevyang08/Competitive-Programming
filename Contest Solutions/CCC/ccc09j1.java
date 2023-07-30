import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = 91;
        
        for (int i = 0; i < 3; i++)
            n += i%2 == 0 ? scanner.nextInt() : scanner.nextInt() * 3;
        
        System.out.println("The 1-3-sum is " + n);
    }
}
