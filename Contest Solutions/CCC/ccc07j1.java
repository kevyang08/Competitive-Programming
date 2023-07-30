import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int[] bowl = new int[3];

    for (int i = 0; i < 3; i++) {
      bowl[i] = scanner.nextInt();
    }

    Arrays.sort(bowl);

    System.out.println(bowl[1]);
  }
}
