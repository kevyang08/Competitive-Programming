import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int[] arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scanner.nextInt();
    }

    System.out.println(solve(arr));
  }

  public static int solve(int[] arr) {
    int m = arr[0], lm = 0;
    for (int i = 0; i < arr.length; i++) {
      lm = Math.max(arr[i], arr[i] + lm);
      if (lm > m) {
        m = lm;
      }
    }
    return m;
  }
}
