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
    if (arr.length == 1) {
      return;
    }
    int[] left = new int[arr.length/2], right = new int[arr.length - left.length];
    for (int i = 0; i < left.length; i++) {
      left[i] = arr[i];
    }
    for (int i = left.length; i < arr.length; i++) {
      right[i - left.length] = arr[i];
    }
    mergeSort(left);
    mergeSort(right);
    merge(arr, left, right);
  }
  public static void merge(int[] arr, int[] left, int[] right) {
    int i = 0, j = 0, k = 0;
    while (i < left.length && j < right.length) {
      if (left[i] < right[j]) {
        arr[k++] = left[i++];
      }
      else {
        arr[k++] = right[j++];
      }
    }
    while (i < left.length) {
      arr[k++] = left[i++];
    }
    while (j < right.length) {
      arr[k++] = right[j++];
    }
  }
}
