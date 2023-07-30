import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int x = scanner.nextInt(), y = scanner.nextInt();
        
        for (int i = 0; i <= y - x; i++) {
            if (i%60 == 0) {
                System.out.println("All positions change in year " + (x + i));
            }
        }
    }
}
