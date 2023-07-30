import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
    	int t = scanner.nextInt();
    	while (t-- > 0) {
    		int w = scanner.nextInt(), h = scanner.nextInt();
    		System.out.println(w > 6 || w > 3 && h > 1 || w > 1 && h > 3 ? "good" : "bad");
    	}
    }
}
