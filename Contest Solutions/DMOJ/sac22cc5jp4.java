import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] adj = new ArrayList[200001];
    static boolean[] vis = new boolean[200001];
    static ArrayList<Integer> list = new ArrayList<Integer>();
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<Integer>();
            int c = scanner.nextInt();
            for (int j = 0; j < c; j++) adj[i].add(scanner.nextInt());
        }
        
        for (int i = n; i >= 1; i--) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        
        for (int i = 0; i < n; i++) {
            System.out.print(i == 0 ? list.get(i) : " " + list.get(i));
        }
        System.out.println();
    }
    public static void dfs(int x) {
        for (int i : adj[x]) 
            if (!vis[i]) 
                dfs(i);
    
        vis[x] = true;
        list.add(x);
    }
}
