import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        long[] arr = new long[3];
        for (int i = 0; i < 3; i++) arr[i] = scanner.nextLong();
        Arrays.sort(arr);
        System.out.println(arr[2] - arr[0] > arr[1] ? -1 : arr[2]);
    }
}
