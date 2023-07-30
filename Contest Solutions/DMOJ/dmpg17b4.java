import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int[] arr = new int[1024];
        for (int i = 1, l = 511, r = 512; i <= 1024; i++) {
        	if (i%2 == 1) arr[r++] = i;
        	else arr[l--] = i;
        }
        for (int i : arr) System.out.println(i);
    }
}
