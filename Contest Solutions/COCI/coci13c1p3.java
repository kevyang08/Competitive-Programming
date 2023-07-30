import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	int n = Integer.parseInt(br.readLine()), arr[][] = new int[n + 1][n + 1], c = 0;
    	for (int i = 1; i <= n; i++) {
    	    StringTokenizer st = new StringTokenizer(br.readLine());
    	    for (int j = 1; j <= n; j++) {
    	        arr[i][j] = Integer.parseInt(st.nextToken()) + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
    	    }
    	}
    	for (int i = 1; i < n; i++) {
    		for (int j = 1; j < n; j++) {
    			HashMap<Integer, Integer> cnt = new HashMap<Integer, Integer>();
    			for (int k = 0; k < i; k++) {
    				for (int l = 0; l < j; l++) {
    					int temp = arr[i][j] - arr[k][j] - arr[i][l] + arr[k][l];
    					if (!cnt.containsKey(temp)) cnt.put(temp, 0);
    					cnt.replace(temp, cnt.get(temp) + 1);
    				}
    			}
    			for (int k = i; k < n; k++) {
    				for (int l = j; l < n; l++) {
    					if (cnt.containsKey(arr[k + 1][l + 1] - arr[i][l + 1] - arr[k + 1][j] + arr[i][j])) c += cnt.get(arr[k + 1][l + 1] - arr[i][l + 1] - arr[k + 1][j] + arr[i][j]);
    				}
    			}
    		}
    	}
    	for (int i = 1; i < n; i++) {
    		for (int j = 1; j < n; j++) {
    			HashMap<Integer, Integer> cnt = new HashMap<Integer, Integer>();
    			for (int k = 0; k < i; k++) {
    				for (int l = j; l < n; l++) {
    					int temp = arr[i][l + 1] - arr[i][j] - arr[k][l + 1] + arr[k][j];
    					if (!cnt.containsKey(temp)) cnt.put(temp, 0);
    					cnt.replace(temp, cnt.get(temp) + 1);
    				}
    			}
    			for (int k = i; k < n; k++) {
    				for (int l = 0; l < j; l++) {
    					if (cnt.containsKey(arr[k + 1][j] - arr[k + 1][l] - arr[i][j] + arr[i][l])) c += cnt.get(arr[k + 1][j] - arr[k + 1][l] - arr[i][j] + arr[i][l]);
    				}
    			}
    		}
    	}
    	System.out.println(c);
    }
}
