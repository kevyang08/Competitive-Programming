import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt();
        System.out.println(n%100/10 + "" + n%10);
    }
}
