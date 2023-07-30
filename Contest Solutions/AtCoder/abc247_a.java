import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        String s = scanner.nextLine();
        System.out.println(0 + s.substring(0, s.length() - 1));
    }
}
