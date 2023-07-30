import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), t = scanner.nextInt();
        scanner.nextLine();
        HashMap<String, HashSet<String>> adj = new HashMap<String, HashSet<String>>();
        HashSet<String> vis = new HashSet<String>();
        adj.put("home", new HashSet<String>());
        adj.put("Waterloo GO", new HashSet<String>());
        Queue<String> q = new LinkedList<String>();
        Queue<Integer> qt = new LinkedList<Integer>();
        for (int i = 0; i < n; i++) adj.put(scanner.nextLine(), new HashSet<String>());
        for (int i = 0; i < t; i++) {
            String[] bruh = scanner.nextLine().split("-");
            adj.get(bruh[0]).add(bruh[1]);
            adj.get(bruh[1]).add(bruh[0]);
        }
        q.offer("home");
        qt.offer(0);
        while (!q.isEmpty()) {
            String cur = q.poll();
            int ct = qt.poll();
            if (vis.contains(cur)) continue;
            vis.add(cur);
            if (cur.equals("Waterloo GO")) {
                System.out.println(ct);
                break;
            }
            for (String s : adj.get(cur)) {
                if (!vis.contains(s)) {
                    q.offer(s);
                    qt.offer(ct + 1);
                }
            }
        }
        if (q.isEmpty()) System.out.println("RIP ACE");
    }
}
