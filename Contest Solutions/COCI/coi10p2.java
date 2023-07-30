import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
//        Scanner scanner = new Scanner(System.in);
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        long arr[] = new long[100000];
        for (int i = 0; i < n; i++) {
        	String[] bruh = br.readLine().split(" - "), a = bruh[0].split(":"), b = bruh[1].split(":");
        	int l = Integer.parseInt(a[0]) * 3600 + Integer.parseInt(a[1]) * 60 + Integer.parseInt(a[2]) + 1, r = Integer.parseInt(b[0]) * 3600 + Integer.parseInt(b[1]) * 60 + Integer.parseInt(b[2]) + 1;
    		arr[l]++;
    		arr[r + 1]--;
    		if (l > r) {
    			arr[1]++;
    			arr[86401]--;
    		}
        }
        for (int i = 1; i < 100000; i++) arr[i] += arr[i - 1];
        for (int i = 1; i < 100000; i++) arr[i] += arr[i - 1];
        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
        	String[] bruh = br.readLine().split(" - "), a = bruh[0].split(":"), b = bruh[1].split(":");
        	int l = Integer.parseInt(a[0]) * 3600 + Integer.parseInt(a[1]) * 60 + Integer.parseInt(a[2]) + 1, r = Integer.parseInt(b[0]) * 3600 + Integer.parseInt(b[1]) * 60 + Integer.parseInt(b[2]) + 1;
        	if (l > r) {
        		double t = 86401 - l + r;
        		System.out.println((arr[86401] - arr[l - 1] + arr[r])/t);
        	}
        	else {
        		double t = r - l + 1;
        		System.out.println((arr[r] - arr[l - 1])/t);
        	}
        }
    }
}
