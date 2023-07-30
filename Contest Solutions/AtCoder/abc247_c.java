import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt(), arr[] = new int[(1 << n) - 1];
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
        	arr[(1 << i) - 1] = i + 1;
        	System.arraycopy(arr, 0, arr, 1 << i, (1 << i) - 1);
        }
        for (int i = 0; i < arr.length; i++) System.out.print(i == 0 ? arr[i] : " " + arr[i]);
        System.out.println();
    }
}
