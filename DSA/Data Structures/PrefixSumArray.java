import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    
    int n = scanner.nextInt();
    int[] arr = new int[n + 1];
    
    for (int i = 1; i <= n; i++) {
      arr[i] = scanner.nextInt() + arr[i - 1];
    }
    
    int l = scanner.nextInt(), r = scanner.nextInt();
    while (l-- != 0 && r != 0) {
      System.out.println(arr[r] - arr[l]);
      l = scanner.nextInt();
      r = scanner.nextInt();
    }
  }
}
