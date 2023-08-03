import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] arr = {1, 2, 3, 4, 5};
        
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt() - 1, b = scanner.nextInt() - 1, temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
        
        for (int i = 0; i < 5; i++) {
            if (arr[i] == 3) {
                System.out.println(i + 1);
            }
        }
    }
}
