import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int k = scanner.nextInt();
        System.out.printf("%2d:%s%d\n", (21 + k/60), (k%60 > 9 ? "" : "0"), k%60);
    }
}
