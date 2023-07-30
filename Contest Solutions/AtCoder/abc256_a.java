import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int n = scanner.nextInt();
        System.out.println(1 << n);
    }
}
