import java.util.*;

class Main {
  static int[] sa, lcp;
  static int n;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String s = scanner.nextLine() + "$";
    n = s.length();
    sa = new int[n];
    build(s);
    for (int i = 0; i < n; i++) {
      System.out.println(s.substring(sa[i]));
    }
    lcp = new int[n];
    buildLcp(s);
    System.out.println(Arrays.toString(lcp));
  }
  public static void build(String s) {
    // each suffix of length 2^(k + 1) can be split into two strings of length 2^k
    Suffix[] arr = new Suffix[n]; // stores the order of the first half, the order of the second half, and the index of all suffixes in string s
    int[] c = new int[n]; // equivalence classes to compare strings of length 2^k in O(1) time
    // initial run for k = 0
    for (int i = 0; i < n; i++) arr[i] = new Suffix((int)s.charAt(i), -1, i);
    Arrays.sort(arr); // sorts by comparing order of first half and second half of two suffixes; position can only change if first halves are equal
    for (int i = 0; i < n; i++) sa[i] = arr[i].idx; // assigns index to position in suffix array
    for (int i = 1; i < n; i++) c[sa[i]] = c[sa[i - 1]] + Integer.compare(arr[i].f, arr[i - 1].f); // increases the order of a suffix by at most 1 from order of previous suffix
    for (int k = 1; k < n; k <<= 1) { // repeat what we did above for k > 0, k is a power of 2
      for (int i = 0; i < n; i++) arr[i] = new Suffix(c[i], c[(i + k)%n], i);
      Arrays.sort(arr);
      for (int i = 0; i < n; i++) sa[i] = arr[i].idx;
      c[sa[0]] = 0;
      for (int i = 1; i < n; i++) c[sa[i]] = c[sa[i - 1]] + (arr[i].f != arr[i - 1].f ? Integer.compare(arr[i].f, arr[i - 1].f) : Integer.compare(arr[i].s, arr[i - 1].s)); // this time we include second half to determine ordering
    }
  }
  public static void buildLcp(String s) {
    int[] rank = new int[n];
    for (int i = 0; i < n; i++) rank[sa[i]] = i; // inverse suffix array
    int k = 0;
    for (int i = 0; i < n; i++) {
      // lcp of last position will always be 0
      if (rank[i] == n - 1) {
        k = 0;
        continue;
      }
      int j = sa[rank[i] + 1]; // gets index of next suffix in suffix array
      while (j + k < n && i + k < n && s.charAt(j + k) == s.charAt(i + k)) k++; // increasing the length of current lcp
      lcp[rank[i]] = k; // assigns the length of current lcp to corresponsing index in lcp array
      if (k > 0) k--; // lcp decreases by at most 1 each time
    }
  }
  public static class Suffix implements Comparable<Suffix> {
    int f, s, idx;
    public Suffix(int f, int s, int idx) {
      this.f = f;
      this.s = s;
      this.idx = idx;
    }
    @Override
    public int compareTo(Suffix o) {
      return f != o.f ? f - o.f : s != o.s ? s - o.s : o.idx - idx;
    }
  }
}
