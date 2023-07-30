import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), q = scanner.nextInt();
        int[] arr = new int[n + 1];
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        map.put("square", 1);
        map.put("circle", 2);
        map.put("triangle", 3);
        while (q-- > 0) {
        	String op = scanner.next(), s = scanner.next();
        	int i = scanner.nextInt();
        	if (op.equals("set")) {
        		arr[i] = map.get(s);
        	}
        	else {
        		System.out.println(map.get(s) == arr[i] ? 1 : 0);
        	}
        }
    }
}
