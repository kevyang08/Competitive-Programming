import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String s = scanner.nextLine();

        System.out.println(s.indexOf("java") == -1 ? s.length() : s.indexOf("java"));
    }
}
