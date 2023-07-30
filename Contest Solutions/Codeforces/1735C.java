import java.io.*;
import java.util.*;
 
public class Main {
	static int[] id = new int[26];
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		while (t-- > 0) {
			Arrays.fill(id, -1);
			int n = scanner.nextInt();
			String s = scanner.next();
			HashMap<Character, Character> map = new HashMap<Character, Character>();
			for (int i = 0; i < n; i++) {
				if (!map.containsKey(s.charAt(i))) {
					for (char j = 'a'; j <= 'z'; j++) {
						if (find(j - 'a') != find(s.charAt(i) - 'a') && !map.containsValue(j)/* && (!map.containsKey(j) || map.get(j) != s.charAt(i))*/) {
							map.put(s.charAt(i), j);
							union(j - 'a', s.charAt(i) - 'a');
							break;
						}
					}
				}
				if (!map.containsKey(s.charAt(i))) {
					for (char j = 'a'; j <= 'z'; j++) {
						if (!map.containsValue(j)) {
							map.put(s.charAt(i), j);
							break;
						}
					}
				}
				System.out.print(map.get(s.charAt(i)));
			}
			System.out.println();
		}
	}
	public static int find(int x) {
		return id[x] < 0 ? x : (id[x] = find(id[x]));
	}
	public static void union(int x, int y) {
		if ((x = find(x)) < (y = find(y))) {
			id[x] += id[y];
			id[y] = x;
		}
		else {
			id[y] += id[x];
			id[x] = y;
		}
	}
}
