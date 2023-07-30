import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), arr[] = new int[n];
        	for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
        	if (n%2 == 1) System.out.println("Mike");
        	else {
        		int[] m = new int[2], idx = new int[2];
        		m[0] = m[1] = 0x3f3f3f3f;
        		for (int i = 0; i < n; i++) {
    				if (arr[i] < m[i%2]) {
    					m[i%2] = arr[i];
    					idx[i%2] = i;
    				}
        		}
        		System.out.println(m[0] == m[1] ? idx[0] > idx[1] ? "Mike" : "Joe" : m[0] > m[1] ? "Mike" : "Joe");
        	}
        }
    }
}
