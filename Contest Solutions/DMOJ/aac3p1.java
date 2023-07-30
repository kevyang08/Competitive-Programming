import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt(), d = scanner.nextInt();
        
        System.out.println(b > a ? d > c ? "Go to the department store" : "Go to the grocery store" : d > c ? "Go to the pharmacy" : "Stay home");
    }
}
