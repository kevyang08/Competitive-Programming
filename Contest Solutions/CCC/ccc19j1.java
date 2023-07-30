import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[] points = new int[2];
        int thp, tp, ft;
        
        for (int i = 0; i < 2; i++) {
            thp = scanner.nextInt();
            tp = scanner.nextInt();
            ft = scanner.nextInt();
            points[i] = 3 * thp + 2 * tp + ft;
        }
        
        System.out.println(points[0] == points[1] ? "T" : points[0] > points[1] ? "A" : "B");
    }
}
