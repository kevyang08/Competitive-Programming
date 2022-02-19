import java.util.*;

class Main {
  static final int R = 257;
  static final int M = 1000000007;
  static long[] hash, pow;
  static int n;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String s = scanner.nextLine();
    n = s.length();
    hash = new long[n + 1]; // stores the hash of each substring s[0:i), 1 <= i <= n, n = |s|
    pow = new long[n + 1];
    hsh(s);
    System.out.println(hash[n]);
  }
  public static void hsh(String s) {
    hash[0] = 0;
    pow[0] = 1;
    for (int i = 1; i <= n; i++) { // string is 0-indexed, hash array is 1-indexed
      // The hash of substring s[0:i) is h = (s[0] * R ^ (i - 1) + s[1] * R ^ (i - 2) + ... + s[i - 2] * R ^ 1 + s[i - 1] * R ^ 0)%M
      // R and M are prime numbers
      hash[i] = (hash[i - 1] * R + s.charAt(i - 1))%M;
      pow[i] = (pow[i - 1] * R)%M;
    }
  }
  public static long getHash(int l, int r) {
    // returns the hash of substring s[l:r]
    // to do this, we need to subtract the hash of substring of s[0:l - 1] from the hash of substring s[0:r]
    // the hash of s[0:r] is pow[r - l + 1]%M times greater than the hash of s[0:l - 1]
    // we add M to prevent negative values
    return (hash[r + 1] - hash[l] * pow[r - l + 1]%M + M)%M;
  }
}
