import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String s = scanner.next();
        int c = 0;
        for (int i = 0; i < s.length(); i++) if ("aeiouy".indexOf(s.charAt(i)) != -1) c++;
        System.out.println(c > 1 ? "good" : "bad");
    }
}
