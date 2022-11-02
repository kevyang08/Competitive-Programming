import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    
    int n = scanner.nextInt();
    int[] arr = new int[n];
    
    for (int i = 0; i < n; i++) {
      arr[i] = scanner.nextInt();
    }

    mergeSort(arr);
    System.out.println(Arrays.toString(arr));
  }
  public static void mergeSort(int[] arr) {
    int[] temp = new int[arr.length];
    for (int i = 1; i < arr.length; i *= 2) {
      for (int j = 0; j < arr.length; j += 2 * i) {
        merge(arr, temp, j, Math.min(j + 2 * i, arr.length), j + i);
      }
    }
  }
  public static void merge(int[] arr, int[] temp, int l, int r, int mid) {
    for (int i = l; i < r; i++) temp[i] = arr[i];
    for (int i = l, j = mid, k = l; k < r; k++) {
      if (j >= r || i < mid && temp[i] < temp[j]) arr[k] = temp[i++];
      else arr[k] = temp[j++];
    }
    System.out.println(Arrays.toString(arr));
  }
}
