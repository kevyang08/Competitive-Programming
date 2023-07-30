import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int d1 = scanner.nextInt(), d2 = scanner.nextInt(), d3 = scanner.nextInt(), d4 = scanner.nextInt();
        
        if (d4 > d3 && d3 > d2 && d2 > d1)
            System.out.println("Fish Rising");
        else if (d4 < d3 && d3 < d2 && d2 < d1)
            System.out.println("Fish Diving");
        else if (d4 == d3 && d3 == d2 && d2 == d1)
            System.out.println("Fish At Constant Depth");
        else
            System.out.println("No Fish");
    }
}
