import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt(), x = scanner.nextInt();
    int[] arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scanner.nextInt();
    }

    System.out.println(ternarySearch(arr, x));
  }
  public static int ternarySearch(int[] arr, int x) {
    int l = 0, r = arr.length - 1;
    while (l <= r) {
      int m1 = l + (r - l)/3, m2 = r - (r - l)/3;
      if (arr[m1] == x) {
        return m1;
      }
      else if (arr[m2] == x) {
        return m2;
      }
      if (arr[m1] > x) {
        r = m1 - 1;
      }
      else if (arr[m2] < x) {
        l = m2 + 1;
      }
      else {
        l = m1 + 1;
        r = m2 - 1;
      }
    }
    return -1;
  }
}
