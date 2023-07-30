import java.util.*;

class Main {
  static int[] lcp;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String s = scanner.nextLine(), t = scanner.nextLine();
    buildLCP(t);
    System.out.println(find(s, t));
    System.out.println(Arrays.toString(lcp));
  }
  public static int find(String s, String t) {
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
      // while the current character in the string doesn't match the current character in the pattern, the current character in the pattern becomes the next letter of the common prefix, or the first character if there is no common prefix
      while (j > 0 && s.charAt(i) != t.charAt(j)) j = lcp[j - 1];
      if (s.charAt(i) == t.charAt(j)) j++; // increment the length of the longest prefix of t that is also a suffix of substring s[i - j, i]
      if (j == t.length()) return i - j + 1; // pattern is found, returns zero-based index of occurence in search string
    }
    return -1; // -1 if not found
  }
  public static void buildLCP(String s) {
    lcp = new int[s.length()];
    int j = 0;
    for (int i = 1; i < s.length(); i++) {
      // while the current character in the pattern doesn't match the current character in the prefix, the current character in the prefix becomes the next letter of the common prefix, or the first character if there is no common prefix
      while (j > 0 && s.charAt(i) != s.charAt(j)) j = lcp[j - 1];
      if (s.charAt(i) == s.charAt(j)) lcp[i] = ++j; // increment the length of longest prefix that is also a suffix of substring s[0, i] and assigns it to current index
    }
  }
}
