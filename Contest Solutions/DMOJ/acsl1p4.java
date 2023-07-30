import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] adj = new ArrayList[21];
    static HashSet<Integer> currNodes = new HashSet<Integer>(), cycle = new HashSet<Integer>();
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), m = scanner.nextInt();
        for (int i = 1; i <= 20; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt(), d = scanner.nextInt();
            if (c > d) adj[a].add(b);
            else adj[b].add(a);
        }
        
        for (int i = 20; i >= 1; i--) dfs(i);
        
        System.out.println(cycle.size());
    }
    public static void dfs(int x) {
        for (int i : adj[x]) {
            if (currNodes.contains(i)) {
                cycle.add(i);
                for (int j : currNodes) cycle.add(j);
                return;
            }
            currNodes.add(i);
            dfs(i);
            currNodes.remove(i);
        }
    }
}
