import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int n = scanner.nextInt(), arr[] = new int[4], p = 0;
        for (int i = 0; i < n; i++) {
        	int a = scanner.nextInt();
        	arr[0] = 1;
        	for (int j = 3; j >= 0; j--) {
        		if (arr[j] == 1) {
	        		if (j + a > 3) {
	        			p++;
	        			arr[j] = 0;
	        		}
	        		else {
	        			arr[j + a] = 1;
	        			arr[j] = 0;
	        		}
        		}
        	}
        }
        System.out.println(p);
    }
}
