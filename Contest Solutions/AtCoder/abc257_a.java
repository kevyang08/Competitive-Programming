import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int n = scanner.nextInt(), k = scanner.nextInt() - 1;
        String thing = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        System.out.println(thing.charAt(k/n));
    }
}
