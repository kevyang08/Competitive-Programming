import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] ans = new String[3], guess = new String[3];
        int[] count = new int[26];
        int g = 0, y = 0;

        for (int i = 0; i < 3; i++) {
            ans[i] = scanner.next();
            for (int j = 0; j < 3; j++) {
                count[ans[i].charAt(j) - 'A']++;
            }
        }

        for (int i = 0; i < 3; i++) {
            guess[i] = scanner.next();
            for (int j = 0; j < 3; j++) {
                if (guess[i].charAt(j) == ans[i].charAt(j)) {
                    g++;
                    count[guess[i].charAt(j) - 'A']--;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (count[guess[i].charAt(j) - 'A'] > 0 && guess[i].charAt(j) != ans[i].charAt(j)) {
                    y++;
                    count[guess[i].charAt(j) - 'A']--;
                }
            }
        }

        System.out.println(g);
        System.out.println(y);
    }
}
