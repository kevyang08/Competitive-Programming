import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    
    long a = scanner.nextLong(), b = scanner.nextLong();
    System.out.println(gcd(a, b));
  }
  public static long gcd(long a, long b) {
    return a%b == 0 ? b : gcd(b, a%b);
  }
}
