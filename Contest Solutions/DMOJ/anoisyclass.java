import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] adj = new ArrayList[10001];
    static boolean[] vis = new boolean[10001];
    static boolean cycle = false;
    static HashSet<Integer> currNodes = new HashSet<Integer>();
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), m = scanner.nextInt();
        for (int i = 1; i <= 10000; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt(), b = scanner.nextInt();
            adj[a].add(b);
        }
        
        for (int i = 10000; i >= 1; i--) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        
        System.out.println(cycle ? "N" : "Y");
    }
    public static void dfs(int x) {
        for (int i : adj[x]) {
            if (!vis[i]) {
                if (currNodes.contains(i)) {
                    cycle = true;
                    return;
                }
                currNodes.add(i);
                dfs(i);
                if (cycle) return;
                currNodes.remove(i);
            }
        }
    
        vis[x] = true;
    }
}
