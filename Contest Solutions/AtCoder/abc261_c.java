import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt();
        String[] arr = new String[n];
        HashMap<String, Integer> cnt = new HashMap<String, Integer>();
        
        for (int i = 0; i < n; i++) {
        	arr[i] = scanner.next();
        	if (!cnt.containsKey(arr[i])) cnt.put(arr[i], -1);
        	cnt.replace(arr[i], cnt.get(arr[i]) + 1);
        	System.out.println(cnt.get(arr[i]) == 0 ? arr[i] : arr[i] + "(" + cnt.get(arr[i]) + ")");
        }
    }
}
