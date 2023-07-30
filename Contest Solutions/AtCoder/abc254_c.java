import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt(), k = scanner.nextInt();
        ArrayList<Integer>[] arr = new ArrayList[k];
        boolean thing = true;
        for (int i = 0; i < k; i++) arr[i] = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) arr[i%k].add(scanner.nextInt());
        for (int i = 0; i < k; i++) Collections.sort(arr[i]);
        for (int i = 1; i < n; i++) if (arr[i%k].get(i/k) < arr[(i - 1)%k].get((i - 1)/k)) thing = false;
        System.out.println(thing ? "Yes" : "No");
    }
}
