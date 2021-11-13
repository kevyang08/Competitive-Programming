import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    
    int n = scanner.nextInt();
    int[] arr = new int[n + 1];
    
    for (int i = 1; i <= n; i++) {
      arr[i] = scanner.nextInt() + arr[i - 1];
    }
    
    int s = scanner.nextInt(), e = scanner.nextInt();
    while (s-- != 0 && e != 0) {
      System.out.println(arr[e] - arr[s]);
      s = scanner.nextInt();
      e = scanner.nextInt();
    }
  }
}
