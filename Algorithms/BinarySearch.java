import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt(), x = scanner.nextInt();
    int[] arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scanner.nextInt();
    }

    System.out.println(binarySearch(arr, x));
  }
  public static int binarySearch(int[] arr, int x) {
    int l = 0, r = arr.length - 1;
    while (l <= r) {
      int i = (l + r)/2, n = arr[i];
      if (n == x) {
        return i;
      }
      else if (x > n) {
        l = i + 1;
      }
      else {
        r = i - 1;
      }
    }
    return -1;
  }
}
