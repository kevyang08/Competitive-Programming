import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        char[] arr = new char[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = scanner.next().charAt(0);
        }
        
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print(arr[scanner.nextInt()]);
        }
    }
}
