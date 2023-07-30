import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int s = scanner.nextInt();
        	
        	if (s < 10) System.out.println(s);
        	
        	else if (s < 18) System.out.printf("%d%d\n", s - 9, 9);
        	
        	else if (s < 25) System.out.printf("%d%d\n", s - 17, 89);
 
        	else if (s < 31) System.out.printf("%d%d\n", s - 24, 789);
 
        	else if (s < 36) System.out.printf("%d%d\n", s - 30, 6789);
 
        	else if (s < 40) System.out.printf("%d%d\n", s - 35, 56789);
 
        	else if (s < 43) System.out.printf("%d%d\n", s - 39, 456789);
 
        	else if (s < 45) System.out.printf("%d%d\n", s - 42, 3456789);
 
        	else System.out.println(123456789);
        }
    }
}
