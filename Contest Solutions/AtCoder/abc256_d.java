import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int n = scanner.nextInt(), arr[] = new int[200002];
        for (int i = 0; i < n; i++) {
        	int l = scanner.nextInt(), r = scanner.nextInt();
        	arr[l]++;
        	arr[r]--;
        }
        int x = -1;
        for (int i = 1; i < 200001; i++) {
        	arr[i] += arr[i - 1];
        	if (x == -1 && arr[i] > 0) x = i;
        	if (x != -1 && arr[i] <= 0) {
        		System.out.printf("%d %d\n", x, i);
        		x = -1;
        	}
        }
    }
}
