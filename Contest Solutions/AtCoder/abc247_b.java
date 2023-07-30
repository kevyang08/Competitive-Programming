import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt();
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        String[] s = new String[n], t = new String[n];
        boolean thing = true;
        for (int i = 0; i < n; i++) {
        	s[i] = scanner.next();
        	t[i] = scanner.next();
        	if (!map.containsKey(s[i])) map.put(s[i], 0);
        	if (!map.containsKey(t[i])) map.put(t[i], 0);
        	map.replace(s[i], map.get(s[i]) + 1);
        	map.replace(t[i], map.get(t[i]) + 1);
        }
        for (int i = 0; i < n; i++) if (s[i].equals(t[i]) && map.get(s[i]) > 2 || map.get(s[i]) > 1 && map.get(t[i]) > 1 && !s[i].equals(t[i])) thing = false;
        System.out.println(thing ? "Yes" : "No");
    }
}
