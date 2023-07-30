import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), l = scanner.nextInt(), s = scanner.nextInt(), prev = 1, cs = 0, c = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>(n, (a, b) -> a.i - b.i);
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt(), b = scanner.nextInt() + 1, ss = scanner.nextInt();
            pq.add(new Pair(a, ss));
            pq.add(new Pair(b, -ss));
        }
        while (!pq.isEmpty()) {
            int cur = pq.peek().i;
            if (cs < s) c += cur - prev;
            cs += pq.poll().s;
            prev = cur;
        }
        if (prev <= l && cs < s) c += l + 1 - prev;
        System.out.println(c);
    }
}

class Pair {
    int i, s;
    public Pair(int i, int s) {
        this.i = i;
        this.s = s;
    }
}
