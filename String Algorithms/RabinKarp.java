import java.util.*;

class Main {
  static final int R = 257;
  static final int M = 1000000007;
  static long[] hash, pow;
  static int n;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String s = scanner.nextLine(), t = scanner.nextLine();
    n = s.length();
    hash = new long[n + 1];
    pow = new long[n + 1];
    hsh(s);
    System.out.println(find(s, t));
  }
  public static int find(String s, String t) {
    long h = getHash(t);
    for (int i = 0; i <= n - t.length(); i++) {
      if (getHash(i, i + t.length()) == h) return i;
    }
    return -1;
  }
  public static void hsh(String s) {
    hash[0] = 0;
    pow[0] = 1;
    for (int i = 1; i <= n; i++) {
      hash[i] = (hash[i - 1] * R + s.charAt(i - 1))%M;
      pow[i] = (pow[i - 1] * R)%M;
    }
  }
  public static long getHash(int l, int r) {
    return (hash[r] - hash[l] * pow[r - l]%M + M)%M;
  }
  public static long getHash(String s) {
    long h = 0;
    for (int i = 0; i < s.length(); i++) {
      h = (h * R + s.charAt(i))%M;
    }
    return h;
  }
}
