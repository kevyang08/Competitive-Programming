import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), arr[] = new int[n], c = 0, thing = 0;
        	for (int i = 0; i < n; i++) {
        		arr[i] = scanner.nextInt();
        		if (i > 0 && arr[i] == arr[i - 1]) thing++;
        	}
        	for (int i = n - 1; i > 0; i--) {
        		if (thing > 1 && arr[i] == arr[i - 1]) {
        			c++;
        			thing--;
        			if (arr[i - 1] != arr[i - 2]) thing++;
        			arr[i - 1] = -1;
        			if (i > 2 && arr[i - 3] == arr[i - 2]) thing--;
        			arr[i - 2] = arr[i - 1];
        		}
        	}
        	System.out.println(c);
        }
    }
}
