import java.util.*;

class Main {
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
    mergeSort(arr, temp, 0, arr.length);
  }
  public static void mergeSort(int[] arr, int[] temp, int l, int r) {
    if (r - l <= 1) return;
    int mid = (l + r) >> 1;
    mergeSort(arr, temp, l, mid);
    mergeSort(arr, temp, mid, r);
    merge(arr, temp, l, r, mid);
  }
  public static void merge(int[] arr, int[] temp, int l, int r, int mid) {
    for (int i = l; i < r; i++) temp[i] = arr[i];
    for (int i = l, j = mid, k = l; k < r; k++) {
      if (j >= r || i < mid && temp[i] < temp[j]) arr[k] = temp[i++];
      else arr[k] = temp[j++];
    }
  }
}
