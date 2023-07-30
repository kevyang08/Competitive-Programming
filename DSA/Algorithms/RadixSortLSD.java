import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int[] arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scanner.nextInt();
    }

    LSD(arr);
    System.out.println(Arrays.toString(arr));
  }
  public static void LSD(int[] arr) {
    int[] temp = new int[arr.length];
    for (int i = 1; i <= 1000000000; i *= 10) {
      int[] count = new int[10];
      for (int n : arr) {
        count[n/i%10]++;
      }
      if (count[0] == arr.length) break;
      for (int j = 1; j < 10; j++) {
        count[j] += count[j - 1];
      }
      for (int j = arr.length - 1; j >= 0; j--) {
        temp[--count[arr[j]/i%10]] = arr[j];
      }
      System.arraycopy(temp, 0, arr, 0, arr.length);
    }
  }
}
