import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[] n = {1, 2, 2, 3, 3, 3, 2, 2, 1, 1};
        
        int i = scanner.nextInt();
        
        System.out.println(n[i - 1]);
    }
}
