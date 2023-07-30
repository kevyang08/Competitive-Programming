import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int count = 0;
        String s;
        
        for (int i = 0; i < 6; i++) {
            s = scanner.next();
            if (s.equals("W"))
                count++;
        }
        
        System.out.println(count > 4 ? 1 : count > 2 ? 2 : count > 0 ? 3 : -1);
    }
}
