import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int[] arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scanner.nextInt();
    }

    System.out.println(ternarySearch(arr));
  }
  public static int ternarySearch(int[] arr) {
    int l = 0, r = arr.length - 1;
    while (l <= r) {
      int m1 = l + (r - l)/3, m2 = r - (r - l)/3;
      if (arr[m1] > arr[m2]) {
        l = m1 + 1;
      }
      else {
        r = m2 - 1;
      }
    }
    return l;
  }
}
