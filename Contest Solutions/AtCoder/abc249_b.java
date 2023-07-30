import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        String s = scanner.nextLine();
        boolean lower = false, upper = false, bruh = true;
        HashSet<Character> set = new HashSet<Character>();
        for (char c = 'A'; c <= 'Z'; c++) set.add(c);
        for (char c = 'a'; c <= 'z'; c++) set.add(c);
        for (int i = 0; i < s.length(); i++) {
        	if (Character.isUpperCase(s.charAt(i))) upper = true;
        	if (Character.isLowerCase(s.charAt(i))) lower = true;
        	if (!set.contains(s.charAt(i))) bruh = false;
        	set.remove(s.charAt(i));
        }
        System.out.println(lower && upper && bruh ? "Yes" : "No");
    }
}
