import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    
    long a = scanner.nextLong(), b = scanner.nextLong();
    System.out.println(gcd(a, b));
  }
  public static long gcd(long a, long b) {
    if (a%b != 0) {
      return gcd(b, a%b);
    }
    return b;
  }
}
