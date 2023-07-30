import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    long n = scanner.nextLong();
    int p = scanner.nextInt();
    System.out.println(pow(n, p));
  }
  public static long pow(long n, int p) {
    long res = 1;
    while (p > 0) {
      if ((p & 1) == 1) {
        res *= n;
      }
      n *= n;
      p >>= 1;
    }
    return res;
  }
}
